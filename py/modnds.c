// osprey modnds
#include <nds.h>
//#include <maxmod9.h>

#include <stdio.h>
#include "py/obj.h"
#include "py/runtime.h"



//input

static mp_obj_t _CHK_U(void) {
     scanKeys();
     if(keysDown() & KEY_DOWN)
     {
         return MP_OBJ_NEW_SMALL_INT(1);
     }
     else
     {
         return MP_OBJ_NEW_SMALL_INT(0);
     }
}


static MP_DEFINE_CONST_FUN_OBJ_0(_CHK_U_obj, _CHK_U);




static mp_obj_t _keysDown(void) {
     mp_int_t keys = keysDown();
     return MP_OBJ_NEW_SMALL_INT(keys);
}

static MP_DEFINE_CONST_FUN_OBJ_0(_keysDown_obj, _keysDown);


static mp_obj_t _scanKeys(void) {
     scanKeys();
     return mp_const_none;
}

static MP_DEFINE_CONST_FUN_OBJ_0(_scanKeys_obj, _scanKeys);


// Function to wait for vertical blank
static mp_obj_t modnds_swi_wait_for_vblank(void) {
     swiWaitForVBlank();
     return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(modnds_swi_wait_for_vblank_obj, modnds_swi_wait_for_vblank);

 // Function to print formatted text to the console
 //static mp_obj_t modnds_iprintf(mp_obj_t format) {
 //    const char *fmt = mp_obj_str_get_str(format);
 //    mp_printf("%s", fmt);
 //    return mp_const_none;
 //}
 //static MP_DEFINE_CONST_FUN_OBJ_1(modnds_iprintf_obj, modnds_iprintf);

 // Define all the functions in the module
static const mp_rom_map_elem_t nds_module_globals_table[] = {
     { MP_ROM_QSTR(MP_QSTR_isUp), MP_ROM_PTR(&_CHK_U_obj) },
     { MP_ROM_QSTR(MP_QSTR_keysDown), MP_ROM_PTR(&_keysDown_obj) },
     { MP_ROM_QSTR(MP_QSTR_scanKeys), MP_ROM_PTR(&_scanKeys_obj) },
     { MP_ROM_QSTR(MP_QSTR_swiWaitForVBlank), MP_ROM_PTR(&modnds_swi_wait_for_vblank_obj) },
     //{ MP_ROM_QSTR(MP_QSTR_iprintf), MP_ROM_PTR(&modnds_iprintf_obj) },
};

static MP_DEFINE_CONST_DICT(nds_module_globals, nds_module_globals_table);

 // Define the module
const mp_obj_module_t nds_module = {
     .base = { &mp_type_module },
     .globals = (mp_obj_dict_t *)&nds_module_globals,
};

// Register the module to make it available in Python

MP_REGISTER_MODULE(MP_QSTR_nds, nds_module);
