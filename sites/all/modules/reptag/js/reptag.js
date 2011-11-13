// $Id: reptag.js,v 1.1.2.1 2008/06/04 16:07:58 profix898 Exp $

Drupal.reptag = {};

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    Drupal.reptag.changed = false;
    //
    $('#reptag-tags-admin-wrapper').each(function() {
      $(this).hide();
      Drupal.reptag.TableRefresh(0);
      $('input.reptag-tags-add').bind('click', function() { Drupal.reptag.AddTag(); return false; });
    });
    //
    $('#reptag-exclude-table').each(function() {
      $('.reptag-exclude-tags', $(this)).attr('readonly', 'readonly');
      $('input.reptag-exclude-append', $(this)).css('display', 'inline').
        bind('click', function() { Drupal.reptag.ExcludeAppendShow($(this)); return false; });
      $('input.reptag-exclude-remove', $(this)).css('display', 'inline').
        bind('click', function() { Drupal.reptag.ExcludeRemoveShow($(this)); return false; });
    });
  });
}

Drupal.reptag.evalResp = function(result) {
  result = Drupal.parseJson(result);
  if (typeof(result) == 'string') {
    return false;
  }
  if (!result.success && result.errors) {
    var message = Drupal.t('One or more errors occured:');
    for (error in result.errors) {
      message = message + '\r\n - ' + result.errors[error];
    }
    alert(message);
    return false;
  }
  
  return result;
};

// Tags administration

Drupal.reptag.TableRefresh = function(page) {
  var wrapper = $('#reptag-tags-admin-wrapper');
  wrapper.block({ message: '', overlayCSS: { backgroundColor: '#fff', opacity: 1.0 } });
  $.ajax({
    url: Drupal.settings.reptag.callback + 'refresh/' + Drupal.settings.reptag.mode,
    data: { page: page, language: Drupal.settings.reptag.language },
    dataType: 'JSON',
    type: 'POST',
    error: function(http){
      alert(Drupal.t('HTTP Request Failure (@status)', { '@status': http.status }));
      wrapper.unblock();
    },
    success: function(result) {
      if (result = Drupal.reptag.evalResp(result)) {
        wrapper.html(result.html);
        $('#reptag-tags-admin-wrapper > form').ajaxForm({
          data: { page: page },
          beforeSubmit: function() { wrapper.block({ message: '', overlayCSS: { backgroundColor: '#fff', opacity: 0.5 } }); },
          success: function(result) {
            if (result = Drupal.reptag.evalResp(result)) {
              Drupal.reptag.TableRefresh(page);
            }
          }
        });
        //
        if (Drupal.settings.reptag.multilingual) {
          $('input.reptag-tags-edit', wrapper).
              bind('click', function() { Drupal.reptag.EditTag($(this)); return false; });
        }
        //
        Drupal.reptag.AhahPager(wrapper);
      }
      wrapper.fadeIn('slow').unblock();
    }
  });
};

Drupal.reptag.AhahPager = function(obj) {
  var pager = $('.pager', obj);
  var last = current = $('li.pager-current', pager).html();
  //
  $('li.pager-item > a', pager).each(function() {
    var page = $(this).html();
    last = Math.max(last, page);
    $(this).attr('href', '#').
      bind('click', function() { Drupal.reptag.TableRefresh(page - 1); return false; });
  });
  //
  $('li.first > a', pager).attr('href', '#').
      bind('click', function() { Drupal.reptag.TableRefresh(0); return false; });
  $('li.pager-previous > a', pager).attr('href', '#').
      bind('click', function() { Drupal.reptag.TableRefresh(current - 2); return false; });
  $('li.pager-next > a', pager).attr('href', '#').
      bind('click', function() { Drupal.reptag.TableRefresh(current); return false; });
  $('li.last > a', pager).attr('href', '#').
      bind('click', function() { Drupal.reptag.TableRefresh(last - 1); return false; });
};

Drupal.reptag.DialogContent = function(request) {
  $.blockUI.defaults.css = {};
  $.blockUI({ message: Drupal.settings.reptag.htmlLoad, overlayCSS: { backgroundColor: '#fff' } });
  $('.reptag-dialog-content').css('height', '40px');
  $.ajax({
    url: Drupal.settings.reptag.callback + request,
    error: function(http){
      alert(Drupal.t('HTTP Request Failure (@status)', { '@status': http.status }));
    },
    success: function(result) {
      if (result = Drupal.reptag.evalResp(result)) {
        $.blockUI({ message: result.html, overlayCSS: { backgroundColor: '#fff' } });
        if (!Drupal.settings.reptag.multilingual) { $('.reptag-dialog-content').css('height', '220px'); }
        $('#reptag-dialog-close').bind('click', function() { $.unblockUI(); return false; });
        $('#reptag-dialog-content > form').ajaxForm({
          success: function(result) {
            if (result = Drupal.reptag.evalResp(result)) {
              Drupal.reptag.TableRefresh(0);
            }
          },
          complete: function() { $.unblockUI(); }
        });
      }
    }
  });
};

Drupal.reptag.AddTag = function() {
  Drupal.reptag.DialogContent('tagadmin/' + Drupal.settings.reptag.mode );
};

Drupal.reptag.EditTag = function(obj) {
  var id = obj.attr('id').replace(/edit-table-([\d]+)-[\w]+/, '$1');
  Drupal.reptag.DialogContent('tagadmin/' + id );
};

// Exclude tags

Drupal.reptag.ExcludeAppendShow = function(obj) {
  $('.reptag-exclude-wrapper').show();
  var wrapper = $('#reptag-exclude-add-wrapper');
  var rid = obj.attr('id').replace(/edit-roles-exclude-table-([\d]+)-[\w]+/, '$1');
  wrapper.show('slow');
  $(':text', wrapper).attr('value', '');
  $(':submit', wrapper).unbind().bind('click', function() { Drupal.reptag.ExcludeAppend(rid); return false; });
};

Drupal.reptag.ExcludeAppend = function(id) {
  var wrapper = $('#reptag-exclude-add-wrapper');
  var textfield = $('#edit-roles-exclude-table-' + id +'-tags');
  var values = textfield.attr('value');
  var add = $(':text', wrapper).attr('value');
  add = add.replace(/^\s+|\s+$/g, '');
  if (add != '' && add != undefined) {
    textfield.attr('value', (!values) ? add : values + '|' + add);
  }
  //
  wrapper.toggle('slow', function() { $('.reptag-exclude-wrapper').hide(); });
  Drupal.reptag.ChangedWarning('.reptag-exclude-wrapper');
};

Drupal.reptag.ExcludeRemoveShow = function(obj) {
  var wrapper = $('#reptag-exclude-remove-wrapper');
  var rid = obj.attr('id').replace(/edit-roles-exclude-table-([\d]+)-[\w]+/, '$1');
  var values = $('#edit-roles-exclude-table-' + rid +'-tags').attr('value');
  if (values != '' && values != undefined) {
    var table = Drupal.theme('reptagExcludeTable', values);
    $('.reptag-exclude-wrapper').show();
    wrapper.empty().html(table).hide().show('slow');
    $('a[name=reptag-exclude-close]', wrapper).bind('click', function() { Drupal.reptag.ExcludeRemoveClose(); return false; });
    $('a:not(name=reptag-exclude-close)', wrapper).bind('click', function() { Drupal.reptag.ExcludeRemove($(this), rid); return false; });
  }
};

Drupal.reptag.ExcludeRemoveClose = function() {
  $('#reptag-exclude-remove-wrapper').toggle('slow', function() { $('.reptag-exclude-wrapper').hide(); }).empty();
};

Drupal.reptag.ExcludeRemove = function(obj, rid) {
  var value = obj.html();
  var textfield = $('#edit-roles-exclude-table-' + rid +'-tags');
  var values = textfield.attr('value');
  //
  var tags = values.split('|');
  tags.splice(tags.indexOf(value), 1);
  values = tags.join('|');
  //
  textfield.attr('value', values);
  $(obj).parents('td').toggle('slow', function() { $(this).remove(); });
  Drupal.reptag.ChangedWarning('.reptag-exclude-wrapper');
  //
  if (values == '' || values == undefined) {
    Drupal.reptag.ExcludeRemoveClose();
  }
};

Drupal.theme.prototype.reptagExcludeTable = function(values) {
  var tags = values.split('|');
  var closelink = Drupal.t('Close');
  var closemsg = Drupal.t('<em>Click to remove.</em>');
  var table = '<table><thead><tr><th></th><th></th><th></th></tr></thead><tbody>';
  table += '<tr class="odd"><td colspan="2">' + closemsg + '</td><td><a href="#" name="reptag-exclude-close">' + closelink + '</a></td></tr>';
  table += '<tr class="even"><td colspan="4"></td></tr>';
  //
  var row = 0;
  while (tags.length) {
    var row_tags = tags.slice(0, 3);
    tags.splice(0, 3);
    row += 1;
    table += '<tr class="' + ((row % 2) ? 'odd' : 'even') + '">';
    for (var tag in row_tags) {
      table += '<td><a href="#">' + row_tags[tag] + '</a></td>';
    }
    table += '</tr>';
  }
  //
  table += '</tbody></table>';
  
  return table;
};

Drupal.reptag.ChangedWarning = function (element) {
  if (!Drupal.reptag.changed) {
    var message = '<div class="warning">' + Drupal.t("Changes made here will not be saved until the form is submitted.") + '</div>';
    $(element).after(message).hide().fadeIn('slow');
    Drupal.reptag.changed = true;
  }
};
