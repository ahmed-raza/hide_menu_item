(function ($) {
  $(document).ready(function(){

      $('.hide').hide();
      $('.page-admin-structure-menu-hide-menu-item .form-wrapper legend span').each(function(){

        var menu_name = $(this).text();
        $(this).click(function(){
            //alert(menu_name);
            $("." + menu_name).toggle('slow');

          });


      });

    });
})(jQuery);
