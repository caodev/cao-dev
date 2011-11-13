/**
 * @author Cody Craven
 * @file addresses.js
 *
 * Rebuild province field with a select list of provinces for country selected
 * on load and on change.
 */
Drupal.behaviors.addresses = function(context) {
  // Bind country changes to reload the province field and
  // load province select element onLoad, do it once.
  // See http://drupal.org/node/817244
  $('.addresses-country-field:not(.addresses-processed)',context)
    .addClass('addresses-processed')
    .bind('change',function(){performProvinceAjax(this);})
    .change();

  // Make province select list call
  function performProvinceAjax(countryElement) {
    // Country field's related province element
    var provinceElement=$(countryElement).parent().siblings().children('.addresses-province-field');
    var attributes={};
    // Iterates over the element attributes to create an object of attributes to pass in the ajax call.
    if(provinceElement.length){
      $.each(provinceElement[0].attributes,function(index,attr){
        if(!(attr.name in{'type':1,'value':1,'size':1,'id':1,'name':1,'class':1})){
          attributes[attr.name]=attr.value;
        }
      });
    }
    $.ajax({
      type:'GET',
      url:Drupal.settings.basePath,
      success:updateProvinceField,
      dataType:'json',
      data:{
        q:'addresses/province_ajax',
        country:$(countryElement).val(),
        field_id:provinceElement.attr('id'),
        field_name:provinceElement.attr('name'),
        passback:provinceElement.parent().attr('id'),
        province:provinceElement.val(),
        language:Drupal.settings.addresses.language,
        'attributes':JSON.stringify(attributes)
      }
    });
  }

  // Populate province field
  function updateProvinceField(data) {
    if(data.hide){
      $('#'+data.passback).hide();
    }else{
      $('#'+data.passback).show();
    }
    $('#'+data.passback).html(data.field);
  }
};
// vim: ts=2 sw=2 et syntax=javascript
