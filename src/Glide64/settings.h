
#ifndef __SETTINGS_H__
#define __SETTINGS_H__

typedef uint32_t wxUint32;

typedef struct {
  int card_id;
  int lang_id;

  wxUint32 res_x, scr_res_x;
  wxUint32 res_y, scr_res_y;
  wxUint32 res_data, res_data_org;

  int advanced_options;
  int texenh_options;
  int ssformat;
  int vsync;

  int show_fps;
  int clock;
  int clock_24_hr;
  int rotate;

  // Polygon Offset Settings
  // These can be used to eliminate stitching artifacts in textures and shadows, which are typically only a problem
  // in mobile/embedded platforms (e.g. Android), where chipsets are inconsistent in their implementation of
  // glPolygonOffset. The float settings (factor and units) are typically set to the same value, and are ignored if
  // force_polygon_offset is False. The float settings (factor and units) are found through trial and error and may be
  // positive or negative. Mario's shadow in Super Mario 64 is a good test case when tuning this value. If the shadow
  // flickers, use a larger magnitude for the float settings. Do not use a larger value than necessary to eliminate
  // artifacts. As a guideline, typical values for mobile chipsets circa 2012-2014 are positive or negative values in
  // the range 0.001 to 2.
  int force_polygon_offset;
  float polygon_offset_factor;
  float polygon_offset_units;

#ifdef USE_FRAMESKIPPER
  int autoframeskip;
  int maxframeskip;
#endif

  int filtering;
  int fog;
  int buff_clear;
  int swapmode;
  int lodmode;
  int aspectmode;
  int use_hotkeys;

  /* game specific settings */
  int special_alt_tex_size;
  int special_use_sts1_only;
  int special_force_calc_sphere;
  int special_correct_viewport;
  int special_increase_texrect_edge;
  int special_decrease_fillrect_edge;
  int special_texture_correction;
  int special_pal230;
  int special_stipple_mode;
  int special_stipple_pattern;
  int special_force_microcheck;
  int special_force_quad3d;
  int special_clip_zmin;
  int special_clip_zmax;
  int special_fast_crc;
  int special_adjust_aspect;
  int special_zmode_compare_less;
  int special_old_style_adither;
  int special_n64_z_scale;
  int special_optimize_texrect;
  int special_ignore_aux_copy;
  int special_hires_buf_clear;
  int special_fb_read_alpha;
  int special_useless_is_useless;
  int special_fb_crc_mode;
  int special_filtering;
  int special_fog;
  int special_buff_clear;
  int special_swapmode;
  int special_aspect;
  int special_lodmode;
  int special_fb_smart;
  int special_fb_hires;
  int special_fb_read_always;
  int special_read_back_to_screen;
  int special_detect_cpu_write;
  int special_fb_get_info;
  int special_fb_render;

  //Frame buffer emulation options
  #define  fb_emulation            (1<<0)   //frame buffer emulation
  #define  fb_hwfbe                (1<<1)   //hardware frame buffer emualtion
  #define  fb_motionblur           (1<<2)   //emulate motion blur
  #define  fb_ref                  (1<<3)   //read every frame
  #define  fb_read_alpha           (1<<4)   //read alpha
  #define  fb_hwfbe_buf_clear      (1<<5)   //clear auxiliary texture frame buffers
  #define  fb_depth_render         (1<<6)   //enable software depth render
  #define  fb_optimize_texrect     (1<<7)   //fast texrect rendering with hwfbe
  #define  fb_ignore_aux_copy      (1<<8)   //do not copy auxiliary frame buffers
  #define  fb_useless_is_useless   (1<<10)  //
  #define  fb_get_info             (1<<11)  //get frame buffer info
  #define  fb_read_back_to_screen  (1<<12)  //render N64 frame buffer to screen
  #define  fb_read_back_to_screen2 (1<<13)  //render N64 frame buffer to screen
  #define  fb_cpu_write_hack       (1<<14)  //show images writed directly by CPU

  #define fb_emulation_enabled ((settings.frame_buffer&fb_emulation)>0)
  #define fb_hwfbe_enabled ((settings.frame_buffer&(fb_emulation|fb_hwfbe))==(fb_emulation|fb_hwfbe))
  #define fb_depth_render_enabled ((settings.frame_buffer&fb_depth_render)>0)

  wxUint32 frame_buffer;
  enum FBCRCMODE {
    fbcrcNone = 0,
    fbcrcFast = 1,
    fbcrcSafe = 2} fb_crc_mode;

#ifdef TEXTURE_FILTER
  //Texture filtering options
  int ghq_fltr;
  int ghq_enht;
  int ghq_cmpr;
  int ghq_hirs;
  int ghq_use;
  int ghq_enht_cmpr;
  int ghq_enht_tile;
  int ghq_enht_f16bpp;
  int ghq_enht_gz;
  int ghq_enht_nobg;
  int ghq_hirs_cmpr;
  int ghq_hirs_tile;
  int ghq_hirs_f16bpp;
  int ghq_hirs_gz;
  int ghq_hirs_altcrc;
  int ghq_cache_save;
  int ghq_cache_size;
  int ghq_hirs_let_texartists_fly;
  int ghq_hirs_dump;
#endif

  //Debug
  int autodetect_ucode;
  int ucode;
  int logging;
  int elogging;
  int log_clear;
  int run_in_window;
  int filter_cache;
  int unk_as_red;
  int log_unk;
  int unk_clear;
  int wireframe;
  int wfmode;

  // Special fixes
  int offset_x, offset_y;
  int scale_x, scale_y;
  int fast_crc;
  int alt_tex_size;
  int use_sts1_only;
  int flame_corona; //hack for zeldas flame's corona
  int increase_texrect_edge; // add 1 to lower right corner coordinates of texrect
  int decrease_fillrect_edge; // sub 1 from lower right corner coordinates of fillrect
  int texture_correction; // enable perspective texture correction emulation. is on by default
  int stipple_mode;  //used for dithered alpha emulation
  wxUint32 stipple_pattern; //used for dithered alpha emulation
  int force_microcheck; //check microcode each frame, for mixed F3DEX-S2DEX games
  int force_quad3d; //force 0xb5 command to be quad, not line 3d
  int clip_zmin; //enable near z clipping
  int clip_zmax; //enable far plane clipping;
  int adjust_aspect; //adjust screen aspect for wide screen mode
  int force_calc_sphere; //use spheric mapping only, Ridge Racer 64
  int pal230;    //set special scale for PAL games
  int correct_viewport; //correct viewport values
  int zmode_compare_less; //force GR_CMP_LESS for zmode=0 (opaque)and zmode=1 (interpenetrating)
  int old_style_adither; //apply alpha dither regardless of alpha_dither_mode
  int n64_z_scale; //scale vertex z value before writing to depth buffer, as N64 does.

  //Special game hacks
  #define  hack_ASB         (1<<0)   //All-Star Baseball games
  #define  hack_Banjo2      (1<<1)   //Banjo Tooie
  #define  hack_BAR         (1<<2)   //Beetle Adventure Racing
  #define  hack_Chopper     (1<<3)   //Chopper Attack
  #define  hack_Diddy       (1<<4)   //diddy kong racing
  #define  hack_Fifa98      (1<<5)   //FIFA - Road to World Cup 98
  #define  hack_Fzero       (1<<6)   //F-Zero
  #define  hack_GoldenEye   (1<<7)   //Golden Eye
  #define  hack_Hyperbike   (1<<8)   //Top Gear Hyper Bike
  #define  hack_ISS64       (1<<9)   //International Superstar Soccer 64
  #define  hack_KI          (1<<10)  //Killer Instinct
  #define  hack_Knockout    (1<<11)  //Knockout Kings 2000
  #define  hack_Lego        (1<<12)  //LEGO Racers
  #define  hack_MK64        (1<<13)  //Mario Kart
  #define  hack_Megaman     (1<<14)  //Megaman64
  #define  hack_Makers      (1<<15)  //Mischief-makers
  #define  hack_WCWnitro    (1<<16)  //WCW Nitro
  #define  hack_Ogre64      (1<<17)  //Ogre Battle 64
  #define  hack_Pilotwings  (1<<18)  //Pilotwings
  #define  hack_PMario      (1<<19)  //Paper Mario
  #define  hack_PPL         (1<<20)  //pokemon puzzle league requires many special fixes
  #define  hack_RE2         (1<<21)  //Resident Evil 2
  #define  hack_Starcraft   (1<<22)  //StarCraft64
  #define  hack_Supercross  (1<<23)  //Supercross 2000
  #define  hack_TGR         (1<<24)  //Top Gear Rally
  #define  hack_TGR2        (1<<25)  //Top Gear Rally 2
  #define  hack_Tonic       (1<<26)  //tonic trouble
  #define  hack_Yoshi       (1<<27)  //Yoshi Story
  #define  hack_Zelda       (1<<28)  //zeldas hacks
  #define  hack_OoT         (1<<29)  //zelda OoT hacks
  wxUint32 hacks;

  //wrapper settings
  int wrpResolution;
  int wrpVRAM;
  int wrpFBO;
  int wrpAnisotropic;
  int wrpAntiAliasing;

} SETTINGS;


#endif
