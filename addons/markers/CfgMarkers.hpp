#define MARKER(a1,b1) class vk_##a1##_##b1##: vk_##a1##_empty { \
    icon = "\x\vk_mods\addons\markers\data\##a1##\##a1##_##b1##.paa"; \
    }
#define MARKERAIR(a2,b2) class vk_##a2##_##b2##: vk_##a2##_empty { \
    icon = "\x\vk_mods\addons\markers\data\##a2##\air\##a2##_##b2##.paa"; \
    }
#define MARKERLEFT(a4,b4) class vk_##a4##_##b4##: vk_##a4##_empty { \
    icon = "\x\vk_mods\addons\markers\data\##a4##\left\##a4##_##b4##.paa"; \
    }
#define MARKERGROUP(a5,b5) class vk_##a5##_##b5##: vk_##a5##_empty { \
    icon = "\x\vk_mods\addons\markers\data\##a5##\group\##a5##_##b5##.paa"; \
    }
#define MARKERINGAME(a6,b6) class vk_s_##b6##: vk_s_empty { \
    name = ##a6##; \
    scope = 2; \
    icon = "\x\vk_mods\addons\markers\data\simple\##b6##.paa"; \
    }

class cfgMarkers {
    class b_unknown;
    class o_unknown;
    class n_unknown;
    class hd_objective;

    class vk_s_empty: n_unknown {
        scope = 0;
        color[] = {0,0,0,1};
    };

    MARKERINGAME("Attack by Fire",ABF);
    MARKERINGAME("Support by Fire",SBF);

    // MARKERINGAME("Secure",secure);
    // MARKERINGAME("Occupy",occupy);
    // MARKERINGAME("Retain",retain);
    // MARKERINGAME("Clear",clear);
    // MARKERINGAME("Destroy",destroy);
    // MARKERINGAME("Neutralize",neutralize);

    class vk_hd_smallDot: hd_objective {
        name = "Small Dot";
        icon = "\x\vk_mods\addons\markers\data\simple\hd_smallDot.paa";
    };

    class vk_b_empty: b_unknown {
        scope = 0;
        icon = "\x\vk_mods\addons\markers\data\b\b_box.paa";
    };
    class vk_o_empty: o_unknown {
        scope = 0;
        icon = "\x\vk_mods\addons\markers\data\o\o_box.paa";
    };
    class vk_n_empty: n_unknown {
        scope = 0;
        icon = "\x\vk_mods\addons\markers\data\n\n_box.paa";
    };
    class vk_u_empty: n_unknown {
        scope = 0;
        icon = "\x\vk_mods\addons\markers\data\u\u_box.paa";
    };
    class vk_v_empty: n_unknown {
        scope = 0;
        color[] = {0,0,0,1};
    };

    class Empty;
    class vk_igConvert: empty {
        scope = 0;
        name = "Special";
    };

    // Special Text Marker
    MARKER(s,text);

    // Common Ground Markers
    MARKER(s,aaa);
    MARKER(s,airassault);
    MARKER(s,airborne);
    MARKER(s,armor);
    MARKER(s,armoraa);
    MARKER(s,arty);
    MARKER(s,damaged);
    MARKER(s,destroyed);
    MARKER(s,eng);
    MARKER(s,engarmor);
    MARKER(s,maint);
    MARKER(s,maintarmor);
    MARKER(s,mlrs);
    MARKER(s,mortar);
    MARKER(s,reduced);
    MARKER(s,reinforced);
    MARKER(s,rereduced);
    MARKER(s,sam);
    MARKER(s,sf);
    MARKER(s,sof);
    MARKER(s,wheeled);

    // Ground Markers
    MARKER(b,aa);
    MARKER(b,amphib);
    MARKER(b,at);
    MARKER(b,hq);
    MARKER(b,ifv);
    MARKER(b,inf);
    MARKER(b,inst);
    MARKER(b,medic);
    MARKER(b,motor);
    MARKER(b,recon);
    MARKER(b,signals);
    MARKER(b,supply);

    MARKER(o,aa);
    MARKER(o,amphib);
    MARKER(o,at);
    MARKER(o,hq);
    MARKER(o,ifv);
    MARKER(o,inf);
    MARKER(o,inst);
    MARKER(o,medic);
    MARKER(o,motor);
    MARKER(o,recon);
    MARKER(o,signals);
    MARKER(o,supply);

    MARKER(n,aa);
    MARKER(n,airassault);
    MARKER(n,amphib);
    MARKER(n,armor);
    MARKER(n,at);
    MARKER(n,engarmor);
    MARKER(n,hq);
    MARKER(n,ifv);
    MARKER(n,inf);
    MARKER(n,inst);
    MARKER(n,maintarmor);
    MARKER(n,medic);
    MARKER(n,motor);
    MARKER(n,recon);
    MARKER(n,signals);
    MARKER(n,supply);

    MARKER(u,aa);
    MARKER(u,amphib);
    MARKER(u,at);
    MARKER(u,hq);
    MARKER(u,ifv);
    MARKER(u,inf);
    MARKER(u,inst);
    MARKER(u,medic);
    MARKER(u,motor);
    MARKER(u,recon);
    MARKER(u,signals);
    MARKER(u,supply);

    // Air Markers
    MARKERAIR(s,airmed);
    MARKERAIR(s,airsof);
    MARKERAIR(s,attack);
    MARKERAIR(s,cargo);
    MARKERAIR(s,fixed);
    MARKERAIR(s,heavy);
    MARKERAIR(s,light);
    MARKERAIR(s,medium);
    MARKERAIR(s,rescue);
    MARKERAIR(s,rotary);
    MARKERAIR(s,scout);
    MARKERAIR(s,uav);
    MARKERAIR(s,utility);
    MARKERAIR(s,vstol);

    MARKERAIR(n,fixed);
    MARKERAIR(n,rotary);

    // Left Side Markers
    MARKERLEFT(s,1);
    MARKERLEFT(s,2);
    MARKERLEFT(s,3);
    MARKERLEFT(s,4);
    MARKERLEFT(s,5);
    MARKERLEFT(s,6);
    MARKERLEFT(s,7);
    MARKERLEFT(s,8);
    MARKERLEFT(s,9);
    MARKERLEFT(s,a);
    MARKERLEFT(s,b);
    MARKERLEFT(s,c);
    MARKERLEFT(s,d);
    MARKERLEFT(s,e);
    MARKERLEFT(s,f);
    MARKERLEFT(s,g);
    MARKERLEFT(s,h);
    MARKERLEFT(s,j);
    MARKERLEFT(s,k);
    MARKERLEFT(s,l);
    MARKERLEFT(s,m);
    MARKERLEFT(s,I);
    MARKERLEFT(s,II);
    MARKERLEFT(s,III);
    MARKERLEFT(s,IV);
    MARKERLEFT(s,V);
    MARKERLEFT(s,VI);

    // Group Markers
    MARKERGROUP(b,group_0);
    MARKERGROUP(b,group_1);
    MARKERGROUP(b,group_2);
    MARKERGROUP(b,group_3);
    MARKERGROUP(b,group_4);
    MARKERGROUP(b,group_5);
    MARKERGROUP(b,group_6);
    MARKERGROUP(b,group_7);
    MARKERGROUP(b,group_8);
    MARKERGROUP(b,group_9);
    MARKERGROUP(b,group_10);
    MARKERGROUP(b,group_11);

    MARKERGROUP(o,group_0);
    MARKERGROUP(o,group_1);
    MARKERGROUP(o,group_2);
    MARKERGROUP(o,group_3);
    MARKERGROUP(o,group_4);
    MARKERGROUP(o,group_5);
    MARKERGROUP(o,group_6);
    MARKERGROUP(o,group_7);
    MARKERGROUP(o,group_8);
    MARKERGROUP(o,group_9);
    MARKERGROUP(o,group_10);
    MARKERGROUP(o,group_11);

    MARKERGROUP(n,group_0);
    MARKERGROUP(n,group_1);
    MARKERGROUP(n,group_2);
    MARKERGROUP(n,group_3);
    MARKERGROUP(n,group_4);
    MARKERGROUP(n,group_5);
    MARKERGROUP(n,group_6);
    MARKERGROUP(n,group_7);
    MARKERGROUP(n,group_8);
    MARKERGROUP(n,group_9);
    MARKERGROUP(n,group_10);
    MARKERGROUP(n,group_11);

    // Vehicle Markers
    MARKER(b,airunit);
    MARKER(o,airunit);
    MARKER(n,airunit);
    MARKER(u,airunit);

    MARKER(v,fighter);
    MARKER(v,fattack);
    MARKER(v,fcargo);
    MARKER(v,fuav);
    MARKER(v,rotary);

    MARKER(b,groundunit);
    MARKER(o,groundunit);
    MARKER(n,groundunit);
    MARKER(u,groundunit);

    MARKER(v,uaaa);
    MARKER(v,uaaa_sp);
    MARKER(v,uapc);
    MARKER(v,uapc_w);
    MARKER(v,uarty);
    MARKER(v,uarty_sp);
    MARKER(v,uifv);
    MARKER(v,uifv_w);
    MARKER(v,umedic);
    MARKER(v,umlrs);
    MARKER(v,umortar);
    MARKER(v,umortar_sp);
    MARKER(v,usp);
    MARKER(v,utank);
    MARKER(v,utank_h);
    MARKER(v,utank_m);
    MARKER(v,utank_l);
    MARKER(v,uutility);
    MARKER(v,uwheeled);
};
