#pragma once
#include <stdint.h>
#include <stddef.h>

struct LedRow
{
    const int *ids;
    uint8_t count;
};

#if defined(FIN_LTM)

// y ~ 66.31
static constexpr int ANIMATION_LED_ROW_0[] = {100};
// y ~ 69.14
static constexpr int ANIMATION_LED_ROW_1[] = {101};
// y ~ 71.85
static constexpr int ANIMATION_LED_ROW_2[] = {102};
// y ~ 74.74
static constexpr int ANIMATION_LED_ROW_3[] = {103};
// y ~ 77.63
static constexpr int ANIMATION_LED_ROW_4[] = {104};
// y ~ 80.33
static constexpr int ANIMATION_LED_ROW_5[] = {105, 121, 122, 123, 124};
// y ~ 81.71
static constexpr int ANIMATION_LED_ROW_6[] = {120};
// y ~ 83.24
static constexpr int ANIMATION_LED_ROW_7[] = {106, 119};
// y ~ 85.68
static constexpr int ANIMATION_LED_ROW_8[] = {107, 118};
// y ~ 87.35
static constexpr int ANIMATION_LED_ROW_9[] = {117};
// y ~ 89.39
static constexpr int ANIMATION_LED_ROW_10[] = {108, 116};
// y ~ 92.54
static constexpr int ANIMATION_LED_ROW_11[] = {109, 115};
// y ~ 94.59
static constexpr int ANIMATION_LED_ROW_12[] = {110, 112, 114};
// y ~ 96.09
static constexpr int ANIMATION_LED_ROW_13[] = {111, 113};
// y ~ 99.45
static constexpr int ANIMATION_LED_ROW_14[] = {125};
// y ~ 101.04
static constexpr int ANIMATION_LED_ROW_15[] = {126};
// y ~ 103.00
static constexpr int ANIMATION_LED_ROW_16[] = {127};
// y ~ 106.17
static constexpr int ANIMATION_LED_ROW_17[] = {128};
// y ~ 109.57
static constexpr int ANIMATION_LED_ROW_18[] = {129, 130};
// y ~ 112.87
static constexpr int ANIMATION_LED_ROW_19[] = {131, 259};
// y ~ 115.74
static constexpr int ANIMATION_LED_ROW_20[] = {132, 260};
// y ~ 118.19
static constexpr int ANIMATION_LED_ROW_21[] = {261, 262};
// y ~ 119.74
static constexpr int ANIMATION_LED_ROW_22[] = {133, 263};
// y ~ 121.89
static constexpr int ANIMATION_LED_ROW_23[] = {134, 264, 265};
// y ~ 123.24
static constexpr int ANIMATION_LED_ROW_24[] = {266};
// y ~ 125.13
static constexpr int ANIMATION_LED_ROW_25[] = {135, 267};
// y ~ 128.21
static constexpr int ANIMATION_LED_ROW_26[] = {136, 268};
// y ~ 130.96
static constexpr int ANIMATION_LED_ROW_27[] = {137, 269};
// y ~ 133.64
static constexpr int ANIMATION_LED_ROW_28[] = {138, 258, 270};
// y ~ 136.16
static constexpr int ANIMATION_LED_ROW_29[] = {141, 140, 139, 257, 271};
// y ~ 137.72
static constexpr int ANIMATION_LED_ROW_30[] = {142, 256};
// y ~ 139.66
static constexpr int ANIMATION_LED_ROW_31[] = {143, 277, 272};
// y ~ 141.49
static constexpr int ANIMATION_LED_ROW_32[] = {144, 255, 276, 275, 274, 273};
// y ~ 143.32
static constexpr int ANIMATION_LED_ROW_33[] = {278, 301};
// y ~ 144.90
static constexpr int ANIMATION_LED_ROW_34[] = {145, 254, 300};
// y ~ 147.48
static constexpr int ANIMATION_LED_ROW_35[] = {146, 253, 279, 299};
// y ~ 150.31
static constexpr int ANIMATION_LED_ROW_36[] = {154, 153, 147, 252, 280, 298};
// y ~ 152.70
static constexpr int ANIMATION_LED_ROW_37[] = {152, 151, 281, 297};
// y ~ 154.26
static constexpr int ANIMATION_LED_ROW_38[] = {150, 148, 251};
// y ~ 156.30
static constexpr int ANIMATION_LED_ROW_39[] = {250, 282, 296};
// y ~ 159.40
static constexpr int ANIMATION_LED_ROW_40[] = {149, 249, 283, 292, 293, 295};
// y ~ 161.82
static constexpr int ANIMATION_LED_ROW_41[] = {235, 236, 248, 284, 291, 294};
// y ~ 163.40
static constexpr int ANIMATION_LED_ROW_42[] = {234, 237, 238, 247, 289, 290};
// y ~ 165.02
static constexpr int ANIMATION_LED_ROW_43[] = {239, 216, 285, 286, 287, 288, 302};
// y ~ 166.70
static constexpr int ANIMATION_LED_ROW_44[] = {233, 244, 219, 218, 217};
// y ~ 168.72
static constexpr int ANIMATION_LED_ROW_45[] = {232, 240, 245, 246, 220, 215, 303};
// y ~ 171.59
static constexpr int ANIMATION_LED_ROW_46[] = {231, 241, 221, 214, 304};
// y ~ 174.32
static constexpr int ANIMATION_LED_ROW_47[] = {230, 242, 222, 213, 311, 305};
// y ~ 176.26
static constexpr int ANIMATION_LED_ROW_48[] = {223, 310, 309, 306};
// y ~ 177.55
static constexpr int ANIMATION_LED_ROW_49[] = {229, 243, 224, 212};
// y ~ 179.83
static constexpr int ANIMATION_LED_ROW_50[] = {228, 226, 225};
// y ~ 181.04
static constexpr int ANIMATION_LED_ROW_51[] = {155, 156, 211, 307};
// y ~ 183.65
static constexpr int ANIMATION_LED_ROW_52[] = {157, 163, 164, 165, 227, 210, 308};
// y ~ 186.15
static constexpr int ANIMATION_LED_ROW_53[] = {158, 161, 162, 166, 167, 209, 312};
// y ~ 188.58
static constexpr int ANIMATION_LED_ROW_54[] = {159, 160, 168, 208, 313};
// y ~ 190.27
static constexpr int ANIMATION_LED_ROW_55[] = {314};
// y ~ 192.30
static constexpr int ANIMATION_LED_ROW_56[] = {170, 169, 207, 315};
// y ~ 194.30
static constexpr int ANIMATION_LED_ROW_57[] = {171, 198, 200, 201, 202, 205, 206, 319, 318, 317, 316};
// y ~ 196.08
static constexpr int ANIMATION_LED_ROW_58[] = {172, 197, 199, 320};
// y ~ 197.73
static constexpr int ANIMATION_LED_ROW_59[] = {196, 203};
// y ~ 199.64
static constexpr int ANIMATION_LED_ROW_60[] = {173, 195, 204, 321};
// y ~ 201.83
static constexpr int ANIMATION_LED_ROW_61[] = {174, 322};
// y ~ 203.65
static constexpr int ANIMATION_LED_ROW_62[] = {175, 176, 177, 193, 194};
// y ~ 206.01
static constexpr int ANIMATION_LED_ROW_63[] = {178, 192, 191};
// y ~ 207.93
static constexpr int ANIMATION_LED_ROW_64[] = {179, 184};
// y ~ 210.11
static constexpr int ANIMATION_LED_ROW_65[] = {180, 181, 182, 183, 185, 190, 189};
// y ~ 212.83
static constexpr int ANIMATION_LED_ROW_66[] = {186, 187, 188};

static constexpr LedRow ANIMATION_LED_ROWS[] = {
  {ANIMATION_LED_ROW_0, 1},
  {ANIMATION_LED_ROW_1, 1},
  {ANIMATION_LED_ROW_2, 1},
  {ANIMATION_LED_ROW_3, 1},
  {ANIMATION_LED_ROW_4, 1},
  {ANIMATION_LED_ROW_5, 5},
  {ANIMATION_LED_ROW_6, 1},
  {ANIMATION_LED_ROW_7, 2},
  {ANIMATION_LED_ROW_8, 2},
  {ANIMATION_LED_ROW_9, 1},
  {ANIMATION_LED_ROW_10, 2},
  {ANIMATION_LED_ROW_11, 2},
  {ANIMATION_LED_ROW_12, 3},
  {ANIMATION_LED_ROW_13, 2},
  {ANIMATION_LED_ROW_14, 1},
  {ANIMATION_LED_ROW_15, 1},
  {ANIMATION_LED_ROW_16, 1},
  {ANIMATION_LED_ROW_17, 1},
  {ANIMATION_LED_ROW_18, 2},
  {ANIMATION_LED_ROW_19, 2},
  {ANIMATION_LED_ROW_20, 2},
  {ANIMATION_LED_ROW_21, 2},
  {ANIMATION_LED_ROW_22, 2},
  {ANIMATION_LED_ROW_23, 3},
  {ANIMATION_LED_ROW_24, 1},
  {ANIMATION_LED_ROW_25, 2},
  {ANIMATION_LED_ROW_26, 2},
  {ANIMATION_LED_ROW_27, 2},
  {ANIMATION_LED_ROW_28, 3},
  {ANIMATION_LED_ROW_29, 5},
  {ANIMATION_LED_ROW_30, 2},
  {ANIMATION_LED_ROW_31, 3},
  {ANIMATION_LED_ROW_32, 6},
  {ANIMATION_LED_ROW_33, 2},
  {ANIMATION_LED_ROW_34, 3},
  {ANIMATION_LED_ROW_35, 4},
  {ANIMATION_LED_ROW_36, 6},
  {ANIMATION_LED_ROW_37, 4},
  {ANIMATION_LED_ROW_38, 3},
  {ANIMATION_LED_ROW_39, 3},
  {ANIMATION_LED_ROW_40, 6},
  {ANIMATION_LED_ROW_41, 6},
  {ANIMATION_LED_ROW_42, 6},
  {ANIMATION_LED_ROW_43, 7},
  {ANIMATION_LED_ROW_44, 5},
  {ANIMATION_LED_ROW_45, 7},
  {ANIMATION_LED_ROW_46, 5},
  {ANIMATION_LED_ROW_47, 6},
  {ANIMATION_LED_ROW_48, 4},
  {ANIMATION_LED_ROW_49, 4},
  {ANIMATION_LED_ROW_50, 3},
  {ANIMATION_LED_ROW_51, 4},
  {ANIMATION_LED_ROW_52, 7},
  {ANIMATION_LED_ROW_53, 7},
  {ANIMATION_LED_ROW_54, 5},
  {ANIMATION_LED_ROW_55, 1},
  {ANIMATION_LED_ROW_56, 4},
  {ANIMATION_LED_ROW_57, 11},
  {ANIMATION_LED_ROW_58, 4},
  {ANIMATION_LED_ROW_59, 2},
  {ANIMATION_LED_ROW_60, 4},
  {ANIMATION_LED_ROW_61, 2},
  {ANIMATION_LED_ROW_62, 5},
  {ANIMATION_LED_ROW_63, 3},
  {ANIMATION_LED_ROW_64, 2},
  {ANIMATION_LED_ROW_65, 7},
  {ANIMATION_LED_ROW_66, 3},
};


#elif defined(HKI_LTM)
// x ~ 18.28
static constexpr int ANIMATION_LED_ROW_0[] = {303, 302, 301, 300};
// x ~ 21.28
static constexpr int ANIMATION_LED_ROW_1[] = {307, 306, 305, 304};
// x ~ 24.28
static constexpr int ANIMATION_LED_ROW_2[] = {311, 310, 309, 308};
// x ~ 27.28
static constexpr int ANIMATION_LED_ROW_3[] = {315, 314, 313, 312};
// x ~ 30.25
static constexpr int ANIMATION_LED_ROW_4[] = {319, 318, 317, 316};
// x ~ 33.38
static constexpr int ANIMATION_LED_ROW_5[] = {105, 106, 321, 320};
// x ~ 36.26
static constexpr int ANIMATION_LED_ROW_6[] = {104, 107, 322, 323};
// x ~ 37.39
static constexpr int ANIMATION_LED_ROW_7[] = {148, 146, 144, 142, 138, 139, 100, 101, 102, 103};
// x ~ 39.43
static constexpr int ANIMATION_LED_ROW_8[] = {150, 147, 145, 143, 141, 140, 137, 111, 110, 109, 108, 325, 324};
// x ~ 41.74
static constexpr int ANIMATION_LED_ROW_9[] = {149, 136, 327, 326};
// x ~ 43.62
static constexpr int ANIMATION_LED_ROW_10[] = {152, 151, 135};
// x ~ 45.93
static constexpr int ANIMATION_LED_ROW_11[] = {154, 153, 134, 329, 328};
// x ~ 48.88
static constexpr int ANIMATION_LED_ROW_12[] = {156, 155, 133, 331, 330};
// x ~ 51.22
static constexpr int ANIMATION_LED_ROW_13[] = {132, 333, 332};
// x ~ 53.60
static constexpr int ANIMATION_LED_ROW_14[] = {158, 157, 131, 335, 334};
// x ~ 56.57
static constexpr int ANIMATION_LED_ROW_15[] = {160, 159, 130, 337, 336};
// x ~ 59.53
static constexpr int ANIMATION_LED_ROW_16[] = {162, 161, 129, 339, 338};
// x ~ 62.49
static constexpr int ANIMATION_LED_ROW_17[] = {164, 163, 128, 341, 340};
// x ~ 65.45
static constexpr int ANIMATION_LED_ROW_18[] = {166, 165, 127, 343, 342};
// x ~ 68.41
static constexpr int ANIMATION_LED_ROW_19[] = {168, 167, 126, 345, 344};
// x ~ 71.37
static constexpr int ANIMATION_LED_ROW_20[] = {170, 169, 125, 347, 346};
// x ~ 73.69
static constexpr int ANIMATION_LED_ROW_21[] = {172, 171, 124};
// x ~ 76.09
static constexpr int ANIMATION_LED_ROW_22[] = {174, 173, 123, 349, 348};
// x ~ 79.06
static constexpr int ANIMATION_LED_ROW_23[] = {176, 175, 122, 351, 350};
// x ~ 82.13
static constexpr int ANIMATION_LED_ROW_24[] = {178, 177, 121, 112, 353, 352};
// x ~ 84.56
static constexpr int ANIMATION_LED_ROW_25[] = {120, 119, 118, 117, 116, 115, 114, 113, 355, 354};
// x ~ 86.54
static constexpr int ANIMATION_LED_ROW_26[] = {180, 179, 357, 356};
// x ~ 89.79
static constexpr int ANIMATION_LED_ROW_27[] = {181, 359, 358};
// x ~ 92.79
static constexpr int ANIMATION_LED_ROW_28[] = {182, 361, 360};
// x ~ 95.79
static constexpr int ANIMATION_LED_ROW_29[] = {183, 363, 362};
// x ~ 98.79
static constexpr int ANIMATION_LED_ROW_30[] = {184, 365, 364};
// x ~ 101.79
static constexpr int ANIMATION_LED_ROW_31[] = {185, 367, 366};
// x ~ 104.80
static constexpr int ANIMATION_LED_ROW_32[] = {186, 369, 368};
// x ~ 107.80
static constexpr int ANIMATION_LED_ROW_33[] = {187, 371, 370};
// x ~ 110.80
static constexpr int ANIMATION_LED_ROW_34[] = {188, 373, 372};
// x ~ 113.75
static constexpr int ANIMATION_LED_ROW_35[] = {189, 378, 374};
// x ~ 116.55
static constexpr int ANIMATION_LED_ROW_36[] = {190, 379, 375};
// x ~ 118.67
static constexpr int ANIMATION_LED_ROW_37[] = {191, 380};
// x ~ 120.88
static constexpr int ANIMATION_LED_ROW_38[] = {192, 381, 376};
// x ~ 122.91
static constexpr int ANIMATION_LED_ROW_39[] = {382, 377};
// x ~ 125.15
static constexpr int ANIMATION_LED_ROW_40[] = {193, 383, 423};
// x ~ 127.18
static constexpr int ANIMATION_LED_ROW_41[] = {194, 384};
// x ~ 128.73
static constexpr int ANIMATION_LED_ROW_42[] = {385, 422};
// x ~ 131.03
static constexpr int ANIMATION_LED_ROW_43[] = {195, 386, 421};
// x ~ 133.18
static constexpr int ANIMATION_LED_ROW_44[] = {196, 387};
// x ~ 134.60
static constexpr int ANIMATION_LED_ROW_45[] = {388, 420};
// x ~ 136.97
static constexpr int ANIMATION_LED_ROW_46[] = {197, 389, 419};
// x ~ 139.18
static constexpr int ANIMATION_LED_ROW_47[] = {198, 390};
// x ~ 140.55
static constexpr int ANIMATION_LED_ROW_48[] = {391, 418};
// x ~ 142.97
static constexpr int ANIMATION_LED_ROW_49[] = {199, 392, 417};
// x ~ 145.18
static constexpr int ANIMATION_LED_ROW_50[] = {200, 393};
// x ~ 146.55
static constexpr int ANIMATION_LED_ROW_51[] = {394, 416};
// x ~ 149.06
static constexpr int ANIMATION_LED_ROW_52[] = {201, 395, 415};
// x ~ 151.97
static constexpr int ANIMATION_LED_ROW_53[] = {202, 396, 414};
// x ~ 154.97
static constexpr int ANIMATION_LED_ROW_54[] = {203, 397, 413};
// x ~ 157.45
static constexpr int ANIMATION_LED_ROW_55[] = {204, 209, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408};
// x ~ 158.53
static constexpr int ANIMATION_LED_ROW_56[] = {409, 412};
// x ~ 161.12
static constexpr int ANIMATION_LED_ROW_57[] = {205, 210, 410, 411};
// x ~ 164.12
static constexpr int ANIMATION_LED_ROW_58[] = {206, 211, 425, 424};
// x ~ 166.98
static constexpr int ANIMATION_LED_ROW_59[] = {207, 212, 426};
// x ~ 169.98
static constexpr int ANIMATION_LED_ROW_60[] = {208, 213, 427};
// x ~ 173.06
static constexpr int ANIMATION_LED_ROW_61[] = {214, 428};
// x ~ 176.06
static constexpr int ANIMATION_LED_ROW_62[] = {215, 429};
// x ~ 179.06
static constexpr int ANIMATION_LED_ROW_63[] = {216, 430};
// x ~ 182.06
static constexpr int ANIMATION_LED_ROW_64[] = {217, 431};
// x ~ 185.06
static constexpr int ANIMATION_LED_ROW_65[] = {218, 432};
// x ~ 188.06
static constexpr int ANIMATION_LED_ROW_66[] = {219, 433};
// x ~ 191.07
static constexpr int ANIMATION_LED_ROW_67[] = {220, 434};
// x ~ 194.07
static constexpr int ANIMATION_LED_ROW_68[] = {221, 435};
// x ~ 197.07
static constexpr int ANIMATION_LED_ROW_69[] = {222, 436};
// x ~ 200.07
static constexpr int ANIMATION_LED_ROW_70[] = {223, 438};
// x ~ 202.94
static constexpr int ANIMATION_LED_ROW_71[] = {224, 437};
// x ~ 205.57
static constexpr int ANIMATION_LED_ROW_72[] = {225, 439};
// x ~ 208.07
static constexpr int ANIMATION_LED_ROW_73[] = {226, 440};
// x ~ 209.57
static constexpr int ANIMATION_LED_ROW_74[] = {441};
// x ~ 211.59
static constexpr int ANIMATION_LED_ROW_75[] = {227, 442};
// x ~ 213.92
static constexpr int ANIMATION_LED_ROW_76[] = {228, 229, 443};
// x ~ 215.67
static constexpr int ANIMATION_LED_ROW_77[] = {233, 232, 231, 230, 444};
// x ~ 217.57
static constexpr int ANIMATION_LED_ROW_78[] = {445};
// x ~ 219.57
static constexpr int ANIMATION_LED_ROW_79[] = {446};
// x ~ 221.69
static constexpr int ANIMATION_LED_ROW_80[] = {453, 452, 451, 450, 449, 448, 447};

static constexpr LedRow ANIMATION_LED_ROWS[] = {
  {ANIMATION_LED_ROW_0, 4},
  {ANIMATION_LED_ROW_1, 4},
  {ANIMATION_LED_ROW_2, 4},
  {ANIMATION_LED_ROW_3, 4},
  {ANIMATION_LED_ROW_4, 4},
  {ANIMATION_LED_ROW_5, 4},
  {ANIMATION_LED_ROW_6, 4},
  {ANIMATION_LED_ROW_7, 10},
  {ANIMATION_LED_ROW_8, 13},
  {ANIMATION_LED_ROW_9, 4},
  {ANIMATION_LED_ROW_10, 3},
  {ANIMATION_LED_ROW_11, 5},
  {ANIMATION_LED_ROW_12, 5},
  {ANIMATION_LED_ROW_13, 3},
  {ANIMATION_LED_ROW_14, 5},
  {ANIMATION_LED_ROW_15, 5},
  {ANIMATION_LED_ROW_16, 5},
  {ANIMATION_LED_ROW_17, 5},
  {ANIMATION_LED_ROW_18, 5},
  {ANIMATION_LED_ROW_19, 5},
  {ANIMATION_LED_ROW_20, 5},
  {ANIMATION_LED_ROW_21, 3},
  {ANIMATION_LED_ROW_22, 5},
  {ANIMATION_LED_ROW_23, 5},
  {ANIMATION_LED_ROW_24, 6},
  {ANIMATION_LED_ROW_25, 10},
  {ANIMATION_LED_ROW_26, 4},
  {ANIMATION_LED_ROW_27, 3},
  {ANIMATION_LED_ROW_28, 3},
  {ANIMATION_LED_ROW_29, 3},
  {ANIMATION_LED_ROW_30, 3},
  {ANIMATION_LED_ROW_31, 3},
  {ANIMATION_LED_ROW_32, 3},
  {ANIMATION_LED_ROW_33, 3},
  {ANIMATION_LED_ROW_34, 3},
  {ANIMATION_LED_ROW_35, 3},
  {ANIMATION_LED_ROW_36, 3},
  {ANIMATION_LED_ROW_37, 2},
  {ANIMATION_LED_ROW_38, 3},
  {ANIMATION_LED_ROW_39, 2},
  {ANIMATION_LED_ROW_40, 3},
  {ANIMATION_LED_ROW_41, 2},
  {ANIMATION_LED_ROW_42, 2},
  {ANIMATION_LED_ROW_43, 3},
  {ANIMATION_LED_ROW_44, 2},
  {ANIMATION_LED_ROW_45, 2},
  {ANIMATION_LED_ROW_46, 3},
  {ANIMATION_LED_ROW_47, 2},
  {ANIMATION_LED_ROW_48, 2},
  {ANIMATION_LED_ROW_49, 3},
  {ANIMATION_LED_ROW_50, 2},
  {ANIMATION_LED_ROW_51, 2},
  {ANIMATION_LED_ROW_52, 3},
  {ANIMATION_LED_ROW_53, 3},
  {ANIMATION_LED_ROW_54, 3},
  {ANIMATION_LED_ROW_55, 13},
  {ANIMATION_LED_ROW_56, 2},
  {ANIMATION_LED_ROW_57, 4},
  {ANIMATION_LED_ROW_58, 4},
  {ANIMATION_LED_ROW_59, 3},
  {ANIMATION_LED_ROW_60, 3},
  {ANIMATION_LED_ROW_61, 2},
  {ANIMATION_LED_ROW_62, 2},
  {ANIMATION_LED_ROW_63, 2},
  {ANIMATION_LED_ROW_64, 2},
  {ANIMATION_LED_ROW_65, 2},
  {ANIMATION_LED_ROW_66, 2},
  {ANIMATION_LED_ROW_67, 2},
  {ANIMATION_LED_ROW_68, 2},
  {ANIMATION_LED_ROW_69, 2},
  {ANIMATION_LED_ROW_70, 2},
  {ANIMATION_LED_ROW_71, 2},
  {ANIMATION_LED_ROW_72, 2},
  {ANIMATION_LED_ROW_73, 2},
  {ANIMATION_LED_ROW_74, 1},
  {ANIMATION_LED_ROW_75, 2},
  {ANIMATION_LED_ROW_76, 3},
  {ANIMATION_LED_ROW_77, 5},
  {ANIMATION_LED_ROW_78, 1},
  {ANIMATION_LED_ROW_79, 1},
  {ANIMATION_LED_ROW_80, 7},
};

#else
static constexpr LedRow ANIMATION_LED_ROWS[] = {};
#endif

static constexpr size_t ANIMATION_LED_ROW_COUNT = sizeof(ANIMATION_LED_ROWS) / sizeof(ANIMATION_LED_ROWS[0]);
static constexpr size_t LED_TOTAL = 223;