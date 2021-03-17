/*
 * kmeans.cpp
 *
 * Code generation for function 'kmeans'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "kmeans.h"
#include "GroupVerticesKMeans_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "GroupVerticesKMeans_data.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 43, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo m_emlrtRSI = { 44, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo n_emlrtRSI = { 53, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo o_emlrtRSI = { 198, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo p_emlrtRSI = { 210, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo q_emlrtRSI = { 320, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo r_emlrtRSI = { 463, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo s_emlrtRSI = { 466, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo t_emlrtRSI = { 468, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo u_emlrtRSI = { 472, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo v_emlrtRSI = { 478, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo w_emlrtRSI = { 483, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo x_emlrtRSI = { 490, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo y_emlrtRSI = { 501, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ab_emlrtRSI = { 507, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo bb_emlrtRSI = { 510, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo cb_emlrtRSI = { 515, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo db_emlrtRSI = { 520, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo eb_emlrtRSI = { 1137, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo fb_emlrtRSI = { 1149, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo gb_emlrtRSI = { 1150, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo hb_emlrtRSI = { 1152, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ib_emlrtRSI = { 1154, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo jb_emlrtRSI = { 1155, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo lb_emlrtRSI = { 1508, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo mb_emlrtRSI = { 1520, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo nb_emlrtRSI = { 1521, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ob_emlrtRSI = { 18, "repmat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRSInfo pb_emlrtRSI = { 557, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo qb_emlrtRSI = { 569, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo rb_emlrtRSI = { 571, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo sb_emlrtRSI = { 575, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo tb_emlrtRSI = { 624, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ub_emlrtRSI = { 629, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo vb_emlrtRSI = { 645, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo wb_emlrtRSI = { 651, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo xb_emlrtRSI = { 662, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo yb_emlrtRSI = { 666, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ac_emlrtRSI = { 668, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo bc_emlrtRSI = { 673, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo cc_emlrtRSI = { 692, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo dc_emlrtRSI = { 699, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ec_emlrtRSI = { 711, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo fc_emlrtRSI = { 714, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo gc_emlrtRSI = { 727, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo hc_emlrtRSI = { 1265, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ic_emlrtRSI = { 1267, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo jc_emlrtRSI = { 1273, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo kc_emlrtRSI = { 1276, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo lc_emlrtRSI = { 1279, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo mc_emlrtRSI = { 1282, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo nc_emlrtRSI = { 1289, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo oc_emlrtRSI = { 1534, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo pc_emlrtRSI = { 1342, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo qc_emlrtRSI = { 1347, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo rc_emlrtRSI = { 768, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo sc_emlrtRSI = { 792, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo tc_emlrtRSI = { 795, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo uc_emlrtRSI = { 802, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo vc_emlrtRSI = { 803, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo wc_emlrtRSI = { 824, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo xc_emlrtRSI = { 1024, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo yc_emlrtRSI = { 1029, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo ad_emlrtRSI = { 1050, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRSInfo bd_emlrtRSI = { 1094, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtMCInfo d_emlrtMCI = { 37, 5, "repmat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 1, 38, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo e_emlrtRTEI = { 41, 5, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo f_emlrtRTEI = { 358, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo g_emlrtRTEI = { 462, 5, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo h_emlrtRTEI = { 471, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo i_emlrtRTEI = { 475, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo j_emlrtRTEI = { 346, 25, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo k_emlrtRTEI = { 1503, 20, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo l_emlrtRTEI = { 541, 52, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo m_emlrtRTEI = { 732, 42, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo o_emlrtRTEI = { 552, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo p_emlrtRTEI = { 553, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo q_emlrtRTEI = { 554, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo r_emlrtRTEI = { 555, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo s_emlrtRTEI = { 1341, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo t_emlrtRTEI = { 766, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo u_emlrtRTEI = { 778, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo v_emlrtRTEI = { 1026, 5, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 521, 29, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtRTEInfo cb_emlrtRTEI = { 150, 27, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo db_emlrtRTEI = { 147, 31, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 45, 26, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 45, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtRTEInfo eb_emlrtRTEI = { 37, 1, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 32, 23, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 30, 23, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 54, 15, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 211, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 218, 26, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 218, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 212, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 521, 34, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 516, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 516, 29, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 516, 39, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 516, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 516, 14, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 511, 18, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 511, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 511, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 502, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 504, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 473, 22, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 473, 29, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 473, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 473, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 464, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 47, 17, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 1522, 18, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 1522, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 1522, 25, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 1523, 17, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 1524, 26, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 1524, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 1524, 17, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 1139, 22, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 1139, 25, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 1150, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 1153, 30, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 1153, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 1138, 18, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 1155, 48, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 1155, 50, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 1155, 37, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 1155, 39, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 1155, 27, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 1155, 29, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 1150, 34, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 1150, 23, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 1150, 25, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 1290, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 1290, 31, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtECInfo emlrtECI = { -1, 659, 21, "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m" };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 659, 23, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 659, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 658, 26, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 627, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 626, 21, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 626, 32, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 626, 30, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 1348, 8, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 1350, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 1343, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 1343, 7, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 1343, 11, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 1344, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 1344, 7, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 1344, 15, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 716, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 716, 23, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 716, 39, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 716, 41, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 716, 55, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 718, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 719, 22, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 719, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 693, 31, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 693, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 640, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 641, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 646, 32, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 652, 32, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 660, 21, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 661, 21, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 1266, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 1287, 13, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 674, 40, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 676, 43, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 680, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 678, 55, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 678, 37, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 1290, 19, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 1290, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 1280, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 1283, 39, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 1283, 44, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 1283, 51, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 1283, 53, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 1283, 27, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 1283, 32, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 1277, 19, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 1277, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 1268, 11, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 1268, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 630, 34, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 630, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 630, 25, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 631, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 632, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 558, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 1274, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 1266, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 1535, 8, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 1535, 15, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 1537, 27, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 1537, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 796, 29, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 796, 31, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 794, 23, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 807, 27, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 1090, 18, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 1091, 18, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 1095, 44, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 1095, 53, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 1095, 60, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 1095, 65, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 1096, 44, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 1096, 53, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 1096, 60, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 1096, 65, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 1073, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 1074, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 1079, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 1080, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 1080, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 1081, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 1081, 5, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 1095, 31, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 1095, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 1095, 19, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 1095, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 1096, 31, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 1096, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 1096, 19, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 1096, 24, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 1051, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 1056, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 1054, 40, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 1030, 12, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 1030, 26, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 1030, 37, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 1030, 44, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 1032, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 1032, 22, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 1032, 36, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 1034, 17, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 793, 21, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 808, 20, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 825, 28, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 828, 55, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 828, 57, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 828, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 828, 35, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 826, 52, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 826, 54, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 826, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 826, 35, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 803, 54, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 803, 56, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 803, 44, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 803, 46, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 803, 33, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 803, 35, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 769, 8, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 771, 9, "", "kmeans",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\stats\\eml\\kmeans.m", 0 };

static emlrtRSInfo dd_emlrtRSI = { 50, "mod",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\mod.m"
};

static emlrtRSInfo ed_emlrtRSI = { 37, "repmat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

/* Function Declarations */
static void b_distfun(const emlrtStack *sp, emxArray_real_T *D, const
                      emxArray_real_T *X, const emxArray_real_T *C, int32_T
                      crows);
static void b_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);
static void batchUpdate(const emlrtStack *sp, const emxArray_real_T *X, int32_T
  k, emxArray_int32_T *idx, emxArray_real_T *C, emxArray_real_T *D,
  emxArray_int32_T *counts, boolean_T *converged, int32_T *iter);
static int32_T countEmpty(const emlrtStack *sp, emxArray_int32_T *empties, const
  emxArray_int32_T *counts, const emxArray_int32_T *changed, int32_T nchanged);
static void distfun(const emlrtStack *sp, emxArray_real_T *D, const
                    emxArray_real_T *X, const emxArray_real_T *C, const
                    emxArray_int32_T *crows, int32_T ncrows);
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void gcentroids(const emlrtStack *sp, emxArray_real_T *C,
  emxArray_int32_T *counts, const emxArray_real_T *X, const emxArray_int32_T
  *idx, const emxArray_int32_T *clusters, int32_T nclusters);
static void mindim2(const emlrtStack *sp, const emxArray_real_T *D,
                    emxArray_real_T *d, emxArray_int32_T *idx);
static boolean_T onlineUpdate(const emlrtStack *sp, const emxArray_real_T *X,
  int32_T k, emxArray_int32_T *idx, emxArray_real_T *C, emxArray_int32_T *counts,
  int32_T *iter);

/* Function Definitions */
static void b_distfun(const emlrtStack *sp, emxArray_real_T *D, const
                      emxArray_real_T *X, const emxArray_real_T *C, int32_T
                      crows)
{
  int32_T n;
  int32_T p;
  int32_T i16;
  int32_T r;
  int32_T j;
  real_T a;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = X->size[0];
  p = X->size[1];
  st.site = &eb_emlrtRSI;
  i16 = C->size[1];
  if (!(1 <= i16)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i16, (emlrtBCInfo *)&lb_emlrtBCI, sp);
  }

  i16 = C->size[0];
  if (!((crows >= 1) && (crows <= i16))) {
    emlrtDynamicBoundsCheckR2012b(crows, 1, i16, (emlrtBCInfo *)&kb_emlrtBCI, sp);
  }

  st.site = &fb_emlrtRSI;
  if ((!(1 > n)) && (n > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (r = 1; r <= n; r++) {
    i16 = X->size[1];
    if (!(1 <= i16)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i16, (emlrtBCInfo *)&mb_emlrtBCI, sp);
    }

    st.site = &gb_emlrtRSI;
    i16 = X->size[0];
    if (!((r >= 1) && (r <= i16))) {
      emlrtDynamicBoundsCheckR2012b(r, 1, i16, (emlrtBCInfo *)&wb_emlrtBCI, &st);
    }

    a = X->data[r - 1] - C->data[crows - 1];
    i16 = D->size[0];
    if (!((r >= 1) && (r <= i16))) {
      emlrtDynamicBoundsCheckR2012b(r, 1, i16, (emlrtBCInfo *)&xb_emlrtBCI, sp);
    }

    i16 = D->size[1];
    if (!((crows >= 1) && (crows <= i16))) {
      emlrtDynamicBoundsCheckR2012b(crows, 1, i16, (emlrtBCInfo *)&yb_emlrtBCI,
        sp);
    }

    D->data[(r + D->size[0] * (crows - 1)) - 1] = a * a;
  }

  st.site = &hb_emlrtRSI;
  if ((!(2 > p)) && (p > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 2; j <= p; j++) {
    i16 = C->size[0];
    if (!((crows >= 1) && (crows <= i16))) {
      emlrtDynamicBoundsCheckR2012b(crows, 1, i16, (emlrtBCInfo *)&nb_emlrtBCI,
        sp);
    }

    i16 = C->size[1];
    if (!((j >= 1) && (j <= i16))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i16, (emlrtBCInfo *)&ob_emlrtBCI, sp);
    }

    st.site = &ib_emlrtRSI;
    for (r = 1; r <= n; r++) {
      st.site = &jb_emlrtRSI;
      i16 = X->size[0];
      if (!(r <= i16)) {
        emlrtDynamicBoundsCheckR2012b(r, 1, i16, (emlrtBCInfo *)&qb_emlrtBCI,
          &st);
      }

      i16 = X->size[1];
      if (!((j >= 1) && (j <= i16))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i16, (emlrtBCInfo *)&rb_emlrtBCI,
          &st);
      }

      a = X->data[(r + X->size[0] * (j - 1)) - 1] - C->data[(crows + C->size[0] *
        (j - 1)) - 1];
      i16 = D->size[0];
      if (!(r <= i16)) {
        emlrtDynamicBoundsCheckR2012b(r, 1, i16, (emlrtBCInfo *)&sb_emlrtBCI, sp);
      }

      i16 = D->size[1];
      if (!((crows >= 1) && (crows <= i16))) {
        emlrtDynamicBoundsCheckR2012b(crows, 1, i16, (emlrtBCInfo *)&tb_emlrtBCI,
          sp);
      }

      i16 = D->size[0];
      if (!(r <= i16)) {
        emlrtDynamicBoundsCheckR2012b(r, 1, i16, (emlrtBCInfo *)&ub_emlrtBCI, sp);
      }

      i16 = D->size[1];
      if (!((crows >= 1) && (crows <= i16))) {
        emlrtDynamicBoundsCheckR2012b(crows, 1, i16, (emlrtBCInfo *)&vb_emlrtBCI,
          sp);
      }

      D->data[(r + D->size[0] * (crows - 1)) - 1] += a * a;
    }
  }
}

static void b_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

static void batchUpdate(const emlrtStack *sp, const emxArray_real_T *X, int32_T
  k, emxArray_int32_T *idx, emxArray_real_T *C, emxArray_real_T *D,
  emxArray_int32_T *counts, boolean_T *converged, int32_T *iter)
{
  emxArray_int32_T *empties;
  int32_T n;
  int32_T i12;
  emxArray_int32_T *previdx;
  int32_T p;
  emxArray_int32_T *moved;
  emxArray_int32_T *changed;
  int32_T j;
  int32_T nchanged;
  real_T prevtotsumD;
  emxArray_real_T *d;
  emxArray_int32_T *nidx;
  emxArray_boolean_T *b;
  emxArray_real_T *b_X;
  int32_T exitg1;
  int32_T nempty;
  real_T totsumD;
  int32_T i;
  int32_T cc;
  int32_T nMoved;
  uint32_T unnamed_idx_0;
  int32_T lonely;
  int32_T from;
  boolean_T overflow;
  boolean_T exitg4;
  boolean_T exitg3;
  int32_T iv11[2];
  int32_T c_X[2];
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &empties, 1, &o_emlrtRTEI, true);
  n = X->size[0];
  i12 = empties->size[0];
  empties->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)empties, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  for (i12 = 0; i12 < k; i12++) {
    empties->data[i12] = 0;
  }

  emxInit_int32_T(sp, &previdx, 1, &p_emlrtRTEI, true);
  i12 = previdx->size[0];
  previdx->size[0] = X->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)previdx, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  p = X->size[0];
  for (i12 = 0; i12 < p; i12++) {
    previdx->data[i12] = 0;
  }

  emxInit_int32_T(sp, &moved, 1, &q_emlrtRTEI, true);
  i12 = moved->size[0];
  moved->size[0] = X->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)moved, i12, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  p = X->size[0];
  for (i12 = 0; i12 < p; i12++) {
    moved->data[i12] = 0;
  }

  emxInit_int32_T(sp, &changed, 1, &r_emlrtRTEI, true);
  i12 = changed->size[0];
  changed->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)changed, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  for (i12 = 0; i12 < k; i12++) {
    changed->data[i12] = 0;
  }

  st.site = &pb_emlrtRSI;
  if ((!(1 > k)) && (k > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= k; j++) {
    i12 = changed->size[0];
    if (!((j >= 1) && (j <= i12))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&ie_emlrtBCI, sp);
    }

    changed->data[j - 1] = j;
  }

  nchanged = k;
  prevtotsumD = rtInf;
  *iter = 0;
  *converged = false;
  emxInit_real_T1(sp, &d, 1, &l_emlrtRTEI, true);
  emxInit_int32_T(sp, &nidx, 1, &l_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b, 1, &s_emlrtRTEI, true);
  emxInit_real_T(sp, &b_X, 2, &l_emlrtRTEI, true);
  do {
    exitg1 = 0;
    (*iter)++;
    st.site = &qb_emlrtRSI;
    gcentroids(&st, C, counts, X, idx, changed, nchanged);
    st.site = &rb_emlrtRSI;
    distfun(&st, D, X, C, changed, nchanged);
    st.site = &sb_emlrtRSI;
    nempty = countEmpty(&st, empties, counts, changed, nchanged);
    if (nempty > 0) {
      st.site = &tb_emlrtRSI;
      if (nempty > 2147483646) {
        b_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i + 1 <= nempty; i++) {
        i12 = d->size[0];
        d->size[0] = n;
        emxEnsureCapacity(sp, (emxArray__common *)d, i12, (int32_T)sizeof(real_T),
                          &l_emlrtRTEI);
        i12 = d->size[0];
        if (!(1 <= i12)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i12, (emlrtBCInfo *)&gc_emlrtBCI,
            sp);
        }

        i12 = D->size[0];
        if (!(1 <= i12)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i12, (emlrtBCInfo *)&ic_emlrtBCI,
            sp);
        }

        i12 = idx->size[0];
        if (!(1 <= i12)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i12, (emlrtBCInfo *)&hc_emlrtBCI,
            sp);
        }

        i12 = D->size[1];
        cc = idx->data[0];
        if (!((cc >= 1) && (cc <= i12))) {
          emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)&hc_emlrtBCI,
            sp);
        }

        d->data[0] = D->data[D->size[0] * (cc - 1)];
        i12 = d->size[0];
        if (!(1 <= i12)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i12, (emlrtBCInfo *)&fc_emlrtBCI,
            sp);
        }

        totsumD = d->data[0];
        lonely = 1;
        st.site = &ub_emlrtRSI;
        if ((!(1 > n)) && (n > 2147483646)) {
          b_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (j = 1; j <= n; j++) {
          i12 = D->size[0];
          if (!((j >= 1) && (j <= i12))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&de_emlrtBCI,
              sp);
          }

          i12 = D->size[1];
          cc = idx->size[0];
          if (!((j >= 1) && (j <= cc))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, cc, (emlrtBCInfo *)&ee_emlrtBCI,
              sp);
          }

          cc = idx->data[j - 1];
          if (!((cc >= 1) && (cc <= i12))) {
            emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)
              &ee_emlrtBCI, sp);
          }

          i12 = d->size[0];
          if (!((j >= 1) && (j <= i12))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&fe_emlrtBCI,
              sp);
          }

          d->data[j - 1] = D->data[(j + D->size[0] * (cc - 1)) - 1];
          i12 = d->size[0];
          if (!((j >= 1) && (j <= i12))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&ge_emlrtBCI,
              sp);
          }

          if (d->data[j - 1] > totsumD) {
            i12 = d->size[0];
            if (!((j >= 1) && (j <= i12))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                &he_emlrtBCI, sp);
            }

            totsumD = d->data[j - 1];
            lonely = j;
          }
        }

        i12 = idx->size[0];
        if (!((lonely >= 1) && (lonely <= i12))) {
          emlrtDynamicBoundsCheckR2012b(lonely, 1, i12, (emlrtBCInfo *)
            &cd_emlrtBCI, sp);
        }

        from = idx->data[lonely - 1];
        i12 = counts->size[0];
        cc = idx->data[lonely - 1];
        if (!((cc >= 1) && (cc <= i12))) {
          emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)&dd_emlrtBCI,
            sp);
        }

        if (counts->data[cc - 1] < 2) {
          st.site = &vb_emlrtRSI;
          j = 1;
          exitg4 = false;
          while ((!exitg4) && (j <= n)) {
            i12 = counts->size[0];
            if (!(j <= i12)) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                &ed_emlrtBCI, sp);
            }

            if (counts->data[j - 1] > 1) {
              from = j;
              exitg4 = true;
            } else {
              j++;
            }
          }

          st.site = &wb_emlrtRSI;
          j = 1;
          exitg3 = false;
          while ((!exitg3) && (j <= n)) {
            i12 = idx->size[0];
            if (!(j <= i12)) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                &fd_emlrtBCI, sp);
            }

            if (idx->data[j - 1] == from) {
              lonely = j;
              exitg3 = true;
            } else {
              j++;
            }
          }
        }

        i12 = empties->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i12))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i12, (emlrtBCInfo *)
            &ec_emlrtBCI, sp);
        }

        i12 = C->size[0];
        cc = empties->data[i];
        if (!((cc >= 1) && (cc <= i12))) {
          emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)&cc_emlrtBCI,
            sp);
        }

        p = C->size[1];
        i12 = nidx->size[0];
        nidx->size[0] = p;
        emxEnsureCapacity(sp, (emxArray__common *)nidx, i12, (int32_T)sizeof
                          (int32_T), &l_emlrtRTEI);
        for (i12 = 0; i12 < p; i12++) {
          nidx->data[i12] = i12;
        }

        i12 = X->size[0];
        if (!((lonely >= 1) && (lonely <= i12))) {
          emlrtDynamicBoundsCheckR2012b(lonely, 1, i12, (emlrtBCInfo *)
            &dc_emlrtBCI, sp);
        }

        iv11[0] = 1;
        iv11[1] = nidx->size[0];
        p = X->size[1];
        i12 = b_X->size[0] * b_X->size[1];
        b_X->size[0] = 1;
        b_X->size[1] = p;
        emxEnsureCapacity(sp, (emxArray__common *)b_X, i12, (int32_T)sizeof
                          (real_T), &l_emlrtRTEI);
        for (i12 = 0; i12 < p; i12++) {
          b_X->data[b_X->size[0] * i12] = X->data[(lonely + X->size[0] * i12) -
            1];
        }

        for (i12 = 0; i12 < 2; i12++) {
          c_X[i12] = b_X->size[i12];
        }

        emlrtSubAssignSizeCheckR2012b(iv11, 2, c_X, 2, (emlrtECInfo *)&emlrtECI,
          sp);
        p = X->size[1] - 1;
        nMoved = empties->data[i];
        for (i12 = 0; i12 <= p; i12++) {
          C->data[(nMoved + C->size[0] * nidx->data[i12]) - 1] = X->data[(lonely
            + X->size[0] * i12) - 1];
        }

        i12 = counts->size[0];
        cc = empties->data[i];
        if (!((cc >= 1) && (cc <= i12))) {
          emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)&gd_emlrtBCI,
            sp);
        }

        counts->data[cc - 1] = 1;
        i12 = idx->size[0];
        if (!((lonely >= 1) && (lonely <= i12))) {
          emlrtDynamicBoundsCheckR2012b(lonely, 1, i12, (emlrtBCInfo *)
            &hd_emlrtBCI, sp);
        }

        idx->data[lonely - 1] = empties->data[i];
        st.site = &xb_emlrtRSI;
        b_distfun(&st, D, X, C, empties->data[i]);
        st.site = &yb_emlrtRSI;
        nMoved = X->size[0];
        p = X->size[1];
        b_st.site = &hc_emlrtRSI;
        i12 = counts->size[0];
        if (!((from >= 1) && (from <= i12))) {
          emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
            &id_emlrtBCI, &st);
        }

        counts->data[from - 1] = 0;
        b_st.site = &ic_emlrtRSI;
        if ((!(1 > p)) && (p > 2147483646)) {
          c_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 1; j <= p; j++) {
          i12 = C->size[0];
          if (!((from >= 1) && (from <= i12))) {
            emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
              &be_emlrtBCI, &st);
          }

          i12 = C->size[1];
          if (!((j >= 1) && (j <= i12))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&ce_emlrtBCI,
              &st);
          }

          C->data[(from + C->size[0] * (j - 1)) - 1] = rtNaN;
        }

        b_st.site = &jc_emlrtRSI;
        cc = 0;
        b_st.site = &kc_emlrtRSI;
        for (j = 1; j <= p; j++) {
          i12 = C->size[0];
          if (!((from >= 1) && (from <= i12))) {
            emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
              &yd_emlrtBCI, &st);
          }

          i12 = C->size[1];
          if (!(j <= i12)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&ae_emlrtBCI,
              &st);
          }

          C->data[(from + C->size[0] * (j - 1)) - 1] = 0.0;
        }

        b_st.site = &lc_emlrtRSI;
        if ((!(1 > nMoved)) && (nMoved > 2147483646)) {
          c_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (lonely = 1; lonely <= nMoved; lonely++) {
          i12 = idx->size[0];
          if (!((lonely >= 1) && (lonely <= i12))) {
            emlrtDynamicBoundsCheckR2012b(lonely, 1, i12, (emlrtBCInfo *)
              &rd_emlrtBCI, &st);
          }

          if (idx->data[lonely - 1] == from) {
            cc++;
            b_st.site = &mc_emlrtRSI;
            for (j = 1; j <= p; j++) {
              i12 = C->size[0];
              if (!((from >= 1) && (from <= i12))) {
                emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
                  &sd_emlrtBCI, &st);
              }

              i12 = C->size[1];
              if (!(j <= i12)) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                  &td_emlrtBCI, &st);
              }

              i12 = X->size[0];
              if (!((lonely >= 1) && (lonely <= i12))) {
                emlrtDynamicBoundsCheckR2012b(lonely, 1, i12, (emlrtBCInfo *)
                  &ud_emlrtBCI, &st);
              }

              i12 = X->size[1];
              if (!(j <= i12)) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                  &vd_emlrtBCI, &st);
              }

              i12 = C->size[0];
              if (!((from >= 1) && (from <= i12))) {
                emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
                  &wd_emlrtBCI, &st);
              }

              i12 = C->size[1];
              if (!(j <= i12)) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                  &xd_emlrtBCI, &st);
              }

              C->data[(from + C->size[0] * (j - 1)) - 1] += X->data[(lonely +
                X->size[0] * (j - 1)) - 1];
            }
          }
        }

        i12 = counts->size[0];
        if (!((from >= 1) && (from <= i12))) {
          emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
            &jd_emlrtBCI, &st);
        }

        counts->data[from - 1] = cc;
        b_st.site = &nc_emlrtRSI;
        for (j = 1; j <= p; j++) {
          i12 = C->size[0];
          if (!((from >= 1) && (from <= i12))) {
            emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
              &bc_emlrtBCI, &st);
          }

          i12 = C->size[1];
          if (!(j <= i12)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&ac_emlrtBCI,
              &st);
          }

          i12 = C->size[0];
          if (!((from >= 1) && (from <= i12))) {
            emlrtDynamicBoundsCheckR2012b(from, 1, i12, (emlrtBCInfo *)
              &pd_emlrtBCI, &st);
          }

          i12 = C->size[1];
          if (!(j <= i12)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&qd_emlrtBCI,
              &st);
          }

          C->data[(from + C->size[0] * (j - 1)) - 1] /= (real_T)cc;
        }

        st.site = &ac_emlrtRSI;
        b_distfun(&st, D, X, C, from);
        if (nchanged < k) {
          st.site = &bc_emlrtRSI;
          j = 1;
          exitg2 = false;
          while ((!exitg2) && (j <= nchanged)) {
            i12 = changed->size[0];
            if (!(j <= i12)) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                &kd_emlrtBCI, sp);
            }

            if (from == changed->data[j - 1]) {
              exitg2 = true;
            } else {
              i12 = changed->size[0];
              if (!(j <= i12)) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                  &ld_emlrtBCI, sp);
              }

              if (from > changed->data[j - 1]) {
                for (p = nchanged; p >= j; p--) {
                  i12 = changed->size[0];
                  if (!(p <= i12)) {
                    emlrtDynamicBoundsCheckR2012b(p, 1, i12, (emlrtBCInfo *)
                      &nd_emlrtBCI, sp);
                  }

                  i12 = changed->size[0];
                  if (!(p + 1 <= i12)) {
                    emlrtDynamicBoundsCheckR2012b(p + 1, 1, i12, (emlrtBCInfo *)
                      &od_emlrtBCI, sp);
                  }

                  changed->data[p] = changed->data[p - 1];
                }

                i12 = changed->size[0];
                if (!(j <= i12)) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)
                    &md_emlrtBCI, sp);
                }

                changed->data[j - 1] = from;
                nchanged++;
                exitg2 = true;
              } else {
                j++;
              }
            }
          }
        }
      }
    }

    totsumD = 0.0;
    st.site = &cc_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 1; i <= n; i++) {
      i12 = D->size[0];
      if (!((i >= 1) && (i <= i12))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)&ad_emlrtBCI, sp);
      }

      i12 = D->size[1];
      cc = idx->size[0];
      if (!((i >= 1) && (i <= cc))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, cc, (emlrtBCInfo *)&bd_emlrtBCI, sp);
      }

      cc = idx->data[i - 1];
      if (!((cc >= 1) && (cc <= i12))) {
        emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)&bd_emlrtBCI,
          sp);
      }

      totsumD += D->data[(i + D->size[0] * (cc - 1)) - 1];
    }

    if (prevtotsumD <= totsumD) {
      i12 = idx->size[0];
      idx->size[0] = previdx->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)idx, i12, (int32_T)sizeof
                        (int32_T), &l_emlrtRTEI);
      p = previdx->size[0];
      for (i12 = 0; i12 < p; i12++) {
        idx->data[i12] = previdx->data[i12];
      }

      st.site = &dc_emlrtRSI;
      gcentroids(&st, C, counts, X, previdx, changed, nchanged);
      (*iter)--;
      exitg1 = 1;
    } else if (*iter >= 1000) {
      exitg1 = 1;
    } else {
      i12 = previdx->size[0];
      previdx->size[0] = idx->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)previdx, i12, (int32_T)sizeof
                        (int32_T), &l_emlrtRTEI);
      p = idx->size[0];
      for (i12 = 0; i12 < p; i12++) {
        previdx->data[i12] = idx->data[i12];
      }

      prevtotsumD = totsumD;
      st.site = &ec_emlrtRSI;
      mindim2(&st, D, d, nidx);
      nMoved = 0;
      st.site = &fc_emlrtRSI;
      for (i = 1; i <= n; i++) {
        i12 = nidx->size[0];
        if (!(i <= i12)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)&rc_emlrtBCI,
            sp);
        }

        i12 = previdx->size[0];
        if (!(i <= i12)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)&sc_emlrtBCI,
            sp);
        }

        if (nidx->data[i - 1] != previdx->data[i - 1]) {
          i12 = D->size[0];
          if (!(i <= i12)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)&tc_emlrtBCI,
              sp);
          }

          i12 = D->size[1];
          cc = previdx->size[0];
          if (!(i <= cc)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, cc, (emlrtBCInfo *)&uc_emlrtBCI,
              sp);
          }

          cc = previdx->data[i - 1];
          if (!((cc >= 1) && (cc <= i12))) {
            emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)
              &uc_emlrtBCI, sp);
          }

          i12 = d->size[0];
          if (!(i <= i12)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)&vc_emlrtBCI,
              sp);
          }

          if (D->data[(i + D->size[0] * (cc - 1)) - 1] > d->data[i - 1]) {
            nMoved++;
            i12 = moved->size[0];
            if (!((nMoved >= 1) && (nMoved <= i12))) {
              emlrtDynamicBoundsCheckR2012b(nMoved, 1, i12, (emlrtBCInfo *)
                &wc_emlrtBCI, sp);
            }

            moved->data[nMoved - 1] = i;
            i12 = nidx->size[0];
            if (!(i <= i12)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)
                &xc_emlrtBCI, sp);
            }

            i12 = idx->size[0];
            if (!(i <= i12)) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i12, (emlrtBCInfo *)
                &yc_emlrtBCI, sp);
            }

            idx->data[i - 1] = nidx->data[i - 1];
          }
        }
      }

      if (nMoved == 0) {
        *converged = true;
        exitg1 = 1;
      } else {
        st.site = &gc_emlrtRSI;
        unnamed_idx_0 = (uint32_T)moved->size[0];
        i12 = b->size[0];
        b->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity(&st, (emxArray__common *)b, i12, (int32_T)sizeof
                          (boolean_T), &l_emlrtRTEI);
        p = (int32_T)unnamed_idx_0;
        for (i12 = 0; i12 < p; i12++) {
          b->data[i12] = false;
        }

        b_st.site = &pc_emlrtRSI;
        if (nMoved > 2147483646) {
          c_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 1; j <= nMoved; j++) {
          i12 = b->size[0];
          cc = idx->size[0];
          p = moved->size[0];
          if (!((j >= 1) && (j <= p))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, p, (emlrtBCInfo *)&nc_emlrtBCI,
              &st);
          }

          p = moved->data[j - 1];
          if (!((p >= 1) && (p <= cc))) {
            emlrtDynamicBoundsCheckR2012b(p, 1, cc, (emlrtBCInfo *)&mc_emlrtBCI,
              &st);
          }

          cc = idx->data[p - 1];
          if (!((cc >= 1) && (cc <= i12))) {
            emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)
              &lc_emlrtBCI, &st);
          }

          b->data[cc - 1] = true;
          i12 = b->size[0];
          cc = previdx->size[0];
          p = moved->size[0];
          if (!((j >= 1) && (j <= p))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, p, (emlrtBCInfo *)&qc_emlrtBCI,
              &st);
          }

          p = moved->data[j - 1];
          if (!((p >= 1) && (p <= cc))) {
            emlrtDynamicBoundsCheckR2012b(p, 1, cc, (emlrtBCInfo *)&pc_emlrtBCI,
              &st);
          }

          cc = previdx->data[p - 1];
          if (!((cc >= 1) && (cc <= i12))) {
            emlrtDynamicBoundsCheckR2012b(cc, 1, i12, (emlrtBCInfo *)
              &oc_emlrtBCI, &st);
          }

          b->data[cc - 1] = true;
        }

        nchanged = 0;
        b_st.site = &qc_emlrtRSI;
        overflow = ((!(1 > b->size[0])) && (b->size[0] > 2147483646));
        if (overflow) {
          c_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 1; j <= b->size[0]; j++) {
          i12 = b->size[0];
          if (!((j >= 1) && (j <= i12))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i12, (emlrtBCInfo *)&jc_emlrtBCI,
              &st);
          }

          if (b->data[j - 1]) {
            nchanged++;
            i12 = changed->size[0];
            if (!((nchanged >= 1) && (nchanged <= i12))) {
              emlrtDynamicBoundsCheckR2012b(nchanged, 1, i12, (emlrtBCInfo *)
                &kc_emlrtBCI, &st);
            }

            changed->data[nchanged - 1] = j;
          }
        }
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_X);
  emxFree_boolean_T(&b);
  emxFree_int32_T(&nidx);
  emxFree_real_T(&d);
  emxFree_int32_T(&changed);
  emxFree_int32_T(&moved);
  emxFree_int32_T(&previdx);
  emxFree_int32_T(&empties);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static int32_T countEmpty(const emlrtStack *sp, emxArray_int32_T *empties, const
  emxArray_int32_T *counts, const emxArray_int32_T *changed, int32_T nchanged)
{
  int32_T nempty;
  int32_T j;
  int32_T i14;
  int32_T i15;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nempty = 0;
  st.site = &oc_emlrtRSI;
  if ((!(1 > nchanged)) && (nchanged > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= nchanged; j++) {
    i14 = counts->size[0];
    i15 = changed->size[0];
    if (!((j >= 1) && (j <= i15))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i15, (emlrtBCInfo *)&me_emlrtBCI, sp);
    }

    i15 = changed->data[j - 1];
    if (!((i15 >= 1) && (i15 <= i14))) {
      emlrtDynamicBoundsCheckR2012b(i15, 1, i14, (emlrtBCInfo *)&le_emlrtBCI, sp);
    }

    if (counts->data[i15 - 1] == 0) {
      nempty++;
      i14 = changed->size[0];
      if (!((j >= 1) && (j <= i14))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i14, (emlrtBCInfo *)&ne_emlrtBCI, sp);
      }

      i14 = empties->size[0];
      if (!((nempty >= 1) && (nempty <= i14))) {
        emlrtDynamicBoundsCheckR2012b(nempty, 1, i14, (emlrtBCInfo *)
          &oe_emlrtBCI, sp);
      }

      empties->data[nempty - 1] = changed->data[j - 1];
    }
  }

  return nempty;
}

static void distfun(const emlrtStack *sp, emxArray_real_T *D, const
                    emxArray_real_T *X, const emxArray_real_T *C, const
                    emxArray_int32_T *crows, int32_T ncrows)
{
  int32_T n;
  int32_T p;
  int32_T i;
  int32_T i11;
  int32_T cr;
  int32_T r;
  int32_T j;
  real_T a;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = X->size[0];
  p = X->size[1];
  st.site = &eb_emlrtRSI;
  if ((!(1 > ncrows)) && (ncrows > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 1; i <= ncrows; i++) {
    i11 = crows->size[0];
    if (!((i >= 1) && (i <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i11, (emlrtBCInfo *)&pb_emlrtBCI, sp);
    }

    cr = crows->data[i - 1];
    i11 = C->size[1];
    if (!(1 <= i11)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i11, (emlrtBCInfo *)&lb_emlrtBCI, sp);
    }

    i11 = C->size[0];
    r = crows->data[i - 1];
    if (!((r >= 1) && (r <= i11))) {
      emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&kb_emlrtBCI, sp);
    }

    st.site = &fb_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (r = 1; r <= n; r++) {
      i11 = X->size[1];
      if (!(1 <= i11)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i11, (emlrtBCInfo *)&mb_emlrtBCI, sp);
      }

      st.site = &gb_emlrtRSI;
      i11 = X->size[0];
      if (!((r >= 1) && (r <= i11))) {
        emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&wb_emlrtBCI,
          &st);
      }

      a = X->data[r - 1] - C->data[cr - 1];
      i11 = D->size[0];
      if (!((r >= 1) && (r <= i11))) {
        emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&xb_emlrtBCI, sp);
      }

      i11 = D->size[1];
      if (!((cr >= 1) && (cr <= i11))) {
        emlrtDynamicBoundsCheckR2012b(cr, 1, i11, (emlrtBCInfo *)&yb_emlrtBCI,
          sp);
      }

      D->data[(r + D->size[0] * (cr - 1)) - 1] = a * a;
    }

    st.site = &hb_emlrtRSI;
    if ((!(2 > p)) && (p > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 2; j <= p; j++) {
      i11 = C->size[0];
      if (!((cr >= 1) && (cr <= i11))) {
        emlrtDynamicBoundsCheckR2012b(cr, 1, i11, (emlrtBCInfo *)&nb_emlrtBCI,
          sp);
      }

      i11 = C->size[1];
      if (!((j >= 1) && (j <= i11))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i11, (emlrtBCInfo *)&ob_emlrtBCI, sp);
      }

      st.site = &ib_emlrtRSI;
      for (r = 1; r <= n; r++) {
        st.site = &jb_emlrtRSI;
        i11 = X->size[0];
        if (!(r <= i11)) {
          emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&qb_emlrtBCI,
            &st);
        }

        i11 = X->size[1];
        if (!((j >= 1) && (j <= i11))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i11, (emlrtBCInfo *)&rb_emlrtBCI,
            &st);
        }

        a = X->data[(r + X->size[0] * (j - 1)) - 1] - C->data[(cr + C->size[0] *
          (j - 1)) - 1];
        i11 = D->size[0];
        if (!(r <= i11)) {
          emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&sb_emlrtBCI,
            sp);
        }

        i11 = D->size[1];
        if (!((cr >= 1) && (cr <= i11))) {
          emlrtDynamicBoundsCheckR2012b(cr, 1, i11, (emlrtBCInfo *)&tb_emlrtBCI,
            sp);
        }

        i11 = D->size[0];
        if (!(r <= i11)) {
          emlrtDynamicBoundsCheckR2012b(r, 1, i11, (emlrtBCInfo *)&ub_emlrtBCI,
            sp);
        }

        i11 = D->size[1];
        if (!((cr >= 1) && (cr <= i11))) {
          emlrtDynamicBoundsCheckR2012b(cr, 1, i11, (emlrtBCInfo *)&vb_emlrtBCI,
            sp);
        }

        D->data[(r + D->size[0] * (cr - 1)) - 1] += a * a;
      }
    }
  }
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      absNumerator = ~(uint32_T)numerator + 1U;
    } else {
      absNumerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(uint32_T)denominator + 1U;
    } else {
      absDenominator = (uint32_T)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

static void gcentroids(const emlrtStack *sp, emxArray_real_T *C,
  emxArray_int32_T *counts, const emxArray_real_T *X, const emxArray_int32_T
  *idx, const emxArray_int32_T *clusters, int32_T nclusters)
{
  int32_T n;
  int32_T p;
  int32_T ic;
  int32_T i13;
  int32_T i;
  int32_T clic;
  int32_T cc;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = X->size[0];
  p = X->size[1];
  st.site = &hc_emlrtRSI;
  if ((!(1 > nclusters)) && (nclusters > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (ic = 1; ic <= nclusters; ic++) {
    i13 = counts->size[0];
    i = clusters->size[0];
    if (!((ic >= 1) && (ic <= i))) {
      emlrtDynamicBoundsCheckR2012b(ic, 1, i, (emlrtBCInfo *)&ke_emlrtBCI, sp);
    }

    i = clusters->data[ic - 1];
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&id_emlrtBCI, sp);
    }

    counts->data[i - 1] = 0;
    st.site = &ic_emlrtRSI;
    if ((!(1 > p)) && (p > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 1; j <= p; j++) {
      i13 = C->size[0];
      i = clusters->size[0];
      if (!((ic >= 1) && (ic <= i))) {
        emlrtDynamicBoundsCheckR2012b(ic, 1, i, (emlrtBCInfo *)&be_emlrtBCI, sp);
      }

      i = clusters->data[ic - 1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&be_emlrtBCI, sp);
      }

      i13 = C->size[1];
      if (!((j >= 1) && (j <= i13))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&ce_emlrtBCI, sp);
      }

      C->data[(i + C->size[0] * (j - 1)) - 1] = rtNaN;
    }
  }

  st.site = &jc_emlrtRSI;
  for (ic = 1; ic <= nclusters; ic++) {
    i13 = clusters->size[0];
    if (!(ic <= i13)) {
      emlrtDynamicBoundsCheckR2012b(ic, 1, i13, (emlrtBCInfo *)&je_emlrtBCI, sp);
    }

    clic = clusters->data[ic - 1];
    cc = 0;
    st.site = &kc_emlrtRSI;
    if ((!(1 > p)) && (p > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 1; j <= p; j++) {
      i13 = C->size[0];
      if (!((clic >= 1) && (clic <= i13))) {
        emlrtDynamicBoundsCheckR2012b(clic, 1, i13, (emlrtBCInfo *)&yd_emlrtBCI,
          sp);
      }

      i13 = C->size[1];
      if (!((j >= 1) && (j <= i13))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&ae_emlrtBCI, sp);
      }

      C->data[(clic + C->size[0] * (j - 1)) - 1] = 0.0;
    }

    st.site = &lc_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 1; i <= n; i++) {
      i13 = idx->size[0];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&rd_emlrtBCI, sp);
      }

      if (idx->data[i - 1] == clic) {
        cc++;
        st.site = &mc_emlrtRSI;
        for (j = 1; j <= p; j++) {
          i13 = C->size[0];
          if (!((clic >= 1) && (clic <= i13))) {
            emlrtDynamicBoundsCheckR2012b(clic, 1, i13, (emlrtBCInfo *)
              &sd_emlrtBCI, sp);
          }

          i13 = C->size[1];
          if (!(j <= i13)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&td_emlrtBCI,
              sp);
          }

          i13 = X->size[0];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ud_emlrtBCI,
              sp);
          }

          i13 = X->size[1];
          if (!(j <= i13)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&vd_emlrtBCI,
              sp);
          }

          i13 = C->size[0];
          if (!((clic >= 1) && (clic <= i13))) {
            emlrtDynamicBoundsCheckR2012b(clic, 1, i13, (emlrtBCInfo *)
              &wd_emlrtBCI, sp);
          }

          i13 = C->size[1];
          if (!(j <= i13)) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&xd_emlrtBCI,
              sp);
          }

          C->data[(clic + C->size[0] * (j - 1)) - 1] += X->data[(i + X->size[0] *
            (j - 1)) - 1];
        }
      }
    }

    i13 = counts->size[0];
    i = clusters->data[ic - 1];
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&jd_emlrtBCI, sp);
    }

    counts->data[i - 1] = cc;
    st.site = &nc_emlrtRSI;
    for (j = 1; j <= p; j++) {
      i13 = C->size[0];
      if (!((clic >= 1) && (clic <= i13))) {
        emlrtDynamicBoundsCheckR2012b(clic, 1, i13, (emlrtBCInfo *)&bc_emlrtBCI,
          sp);
      }

      i13 = C->size[1];
      if (!(j <= i13)) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&ac_emlrtBCI, sp);
      }

      i13 = C->size[0];
      if (!((clic >= 1) && (clic <= i13))) {
        emlrtDynamicBoundsCheckR2012b(clic, 1, i13, (emlrtBCInfo *)&pd_emlrtBCI,
          sp);
      }

      i13 = C->size[1];
      if (!(j <= i13)) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i13, (emlrtBCInfo *)&qd_emlrtBCI, sp);
      }

      C->data[(clic + C->size[0] * (j - 1)) - 1] /= (real_T)cc;
    }
  }
}

static void mindim2(const emlrtStack *sp, const emxArray_real_T *D,
                    emxArray_real_T *d, emxArray_int32_T *idx)
{
  int32_T n;
  int32_T i;
  int32_T j;
  int32_T i7;
  const mxArray *y;
  char_T u[15];
  static const char_T cv2[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *m2;
  static const int32_T iv5[2] = { 1, 15 };

  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = D->size[0];
  st.site = &lb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  i = D->size[0];
  j = D->size[0];
  if (i == j) {
  } else {
    for (i7 = 0; i7 < 15; i7++) {
      u[i7] = cv2[i7];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(&st, 15, m2, &u[0]);
    emlrtAssign(&y, m2);
    b_st.site = &ed_emlrtRSI;
    b_error(&b_st, y, (emlrtMCInfo *)&d_emlrtMCI);
  }

  i7 = d->size[0];
  d->size[0] = i;
  emxEnsureCapacity(&st, (emxArray__common *)d, i7, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  for (i7 = 0; i7 < i; i7++) {
    d->data[i7] = rtInf;
  }

  i7 = idx->size[0];
  idx->size[0] = D->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)idx, i7, (int32_T)sizeof(int32_T),
                    &k_emlrtRTEI);
  j = D->size[0];
  for (i7 = 0; i7 < j; i7++) {
    idx->data[i7] = 1;
  }

  st.site = &mb_emlrtRSI;
  overflow = ((!(1 > D->size[1])) && (D->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= D->size[1]; j++) {
    st.site = &nb_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 1; i <= n; i++) {
      i7 = D->size[0];
      if (!((i >= 1) && (i <= i7))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i7, (emlrtBCInfo *)&db_emlrtBCI, sp);
      }

      i7 = D->size[1];
      if (!((j >= 1) && (j <= i7))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i7, (emlrtBCInfo *)&eb_emlrtBCI, sp);
      }

      i7 = d->size[0];
      if (!((i >= 1) && (i <= i7))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i7, (emlrtBCInfo *)&fb_emlrtBCI, sp);
      }

      if (D->data[(i + D->size[0] * (j - 1)) - 1] < d->data[i - 1]) {
        i7 = idx->size[0];
        if (!((i >= 1) && (i <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i7, (emlrtBCInfo *)&gb_emlrtBCI,
            sp);
        }

        idx->data[i - 1] = j;
        i7 = D->size[0];
        if (!((i >= 1) && (i <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i7, (emlrtBCInfo *)&hb_emlrtBCI,
            sp);
        }

        i7 = D->size[1];
        if (!((j >= 1) && (j <= i7))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i7, (emlrtBCInfo *)&ib_emlrtBCI,
            sp);
        }

        i7 = d->size[0];
        if (!((i >= 1) && (i <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i7, (emlrtBCInfo *)&jb_emlrtBCI,
            sp);
        }

        d->data[i - 1] = D->data[(i + D->size[0] * (j - 1)) - 1];
      }
    }
  }
}

static boolean_T onlineUpdate(const emlrtStack *sp, const emxArray_real_T *X,
  int32_T k, emxArray_int32_T *idx, emxArray_real_T *C, emxArray_int32_T *counts,
  int32_T *iter)
{
  boolean_T converged;
  emxArray_int32_T *changed;
  int32_T n;
  int32_T p;
  int32_T i17;
  int32_T nchanged;
  int32_T nidx;
  emxArray_real_T *Del;
  int32_T lastmoved;
  int32_T nummoved;
  int32_T iter1;
  int32_T modmin;
  emxArray_int32_T *moved;
  emxArray_real_T *minDel;
  emxArray_int32_T *b_nidx;
  boolean_T exitg1;
  int32_T ic;
  int32_T nmoved;
  int32_T c;
  int32_T mvScalar;
  int32_T i18;
  boolean_T guard1 = false;
  real_T aMember;
  real_T aNonMember;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &changed, 1, &t_emlrtRTEI, true);
  n = X->size[0];
  p = X->size[1];
  i17 = changed->size[0];
  changed->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)changed, i17, (int32_T)sizeof
                    (int32_T), &m_emlrtRTEI);
  for (i17 = 0; i17 < k; i17++) {
    changed->data[i17] = 0;
  }

  nchanged = 0;
  st.site = &rc_emlrtRSI;
  if ((!(1 > k)) && (k > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (nidx = 1; nidx <= k; nidx++) {
    i17 = counts->size[0];
    if (!((k >= 1) && (k <= i17))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, i17, (emlrtBCInfo *)&wg_emlrtBCI, sp);
    }

    if (counts->data[k - 1] > 0) {
      nchanged++;
      i17 = changed->size[0];
      if (!((nchanged >= 1) && (nchanged <= i17))) {
        emlrtDynamicBoundsCheckR2012b(nchanged, 1, i17, (emlrtBCInfo *)
          &xg_emlrtBCI, sp);
      }

      changed->data[nchanged - 1] = nidx;
    }
  }

  emxInit_real_T(sp, &Del, 2, &u_emlrtRTEI, true);
  lastmoved = 1;
  nummoved = 0;
  iter1 = *iter;
  converged = false;
  i17 = Del->size[0] * Del->size[1];
  Del->size[0] = X->size[0];
  Del->size[1] = k;
  emxEnsureCapacity(sp, (emxArray__common *)Del, i17, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  modmin = X->size[0] * k;
  for (i17 = 0; i17 < modmin; i17++) {
    Del->data[i17] = rtNaN;
  }

  emxInit_int32_T(sp, &moved, 1, &v_emlrtRTEI, true);
  emxInit_real_T1(sp, &minDel, 1, &m_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_nidx, 1, &m_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (*iter < 1000)) {
    st.site = &sc_emlrtRSI;
    if ((!(1 > nchanged)) && (nchanged > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ic = 0; ic + 1 <= nchanged; ic++) {
      i17 = changed->size[0];
      if (!((ic + 1 >= 1) && (ic + 1 <= i17))) {
        emlrtDynamicBoundsCheckR2012b(ic + 1, 1, i17, (emlrtBCInfo *)
          &fg_emlrtBCI, sp);
      }

      c = changed->data[ic];
      modmin = Del->size[0];
      mvScalar = Del->size[1];
      nmoved = changed->data[ic];
      if (!((nmoved >= 1) && (nmoved <= mvScalar))) {
        emlrtDynamicBoundsCheckR2012b(nmoved, 1, mvScalar, (emlrtBCInfo *)
          &re_emlrtBCI, sp);
      }

      for (i17 = 0; i17 < modmin; i17++) {
        Del->data[i17 + Del->size[0] * (nmoved - 1)] = 0.0;
      }

      st.site = &tc_emlrtRSI;
      if ((!(1 > p)) && (p > 2147483646)) {
        b_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (mvScalar = 1; mvScalar <= p; mvScalar++) {
        i17 = C->size[0];
        if (!((c >= 1) && (c <= i17))) {
          emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&pe_emlrtBCI,
            sp);
        }

        i17 = C->size[1];
        if (!((mvScalar >= 1) && (mvScalar <= i17))) {
          emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
            &qe_emlrtBCI, sp);
        }

        st.site = &uc_emlrtRSI;
        if ((!(1 > n)) && (n > 2147483646)) {
          b_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (nidx = 1; nidx <= n; nidx++) {
          st.site = &vc_emlrtRSI;
          i17 = X->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &qg_emlrtBCI, &st);
          }

          i17 = X->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &rg_emlrtBCI, &st);
          }

          aMember = X->data[(nidx + X->size[0] * (mvScalar - 1)) - 1] - C->data
            [(c + C->size[0] * (mvScalar - 1)) - 1];
          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &sg_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&tg_emlrtBCI,
              sp);
          }

          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &ug_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&vg_emlrtBCI,
              sp);
          }

          Del->data[(nidx + Del->size[0] * (c - 1)) - 1] += aMember * aMember;
        }
      }

      i17 = counts->size[0];
      i18 = changed->data[ic];
      if (!((i18 >= 1) && (i18 <= i17))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)&se_emlrtBCI,
          sp);
      }

      i17 = counts->size[0];
      i18 = changed->data[ic];
      if (!((i18 >= 1) && (i18 <= i17))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)&gg_emlrtBCI,
          sp);
      }

      if (counts->data[i18 - 1] == 1) {
        aMember = 0.0;
      } else {
        aMember = (real_T)counts->data[changed->data[ic] - 1] / ((real_T)
          counts->data[changed->data[ic] - 1] - 1.0);
      }

      aNonMember = (real_T)counts->data[changed->data[ic] - 1] / ((real_T)
        counts->data[changed->data[ic] - 1] + 1.0);
      st.site = &wc_emlrtRSI;
      if ((!(1 > n)) && (n > 2147483646)) {
        b_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (nidx = 1; nidx <= n; nidx++) {
        i17 = idx->size[0];
        if (!((nidx >= 1) && (nidx <= i17))) {
          emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
            &hg_emlrtBCI, sp);
        }

        if (idx->data[nidx - 1] == c) {
          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &mg_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&ng_emlrtBCI,
              sp);
          }

          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &og_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&pg_emlrtBCI,
              sp);
          }

          Del->data[(nidx + Del->size[0] * (c - 1)) - 1] *= aMember;
        } else {
          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &ig_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&jg_emlrtBCI,
              sp);
          }

          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &kg_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          if (!((c >= 1) && (c <= i17))) {
            emlrtDynamicBoundsCheckR2012b(c, 1, i17, (emlrtBCInfo *)&lg_emlrtBCI,
              sp);
          }

          Del->data[(nidx + Del->size[0] * (c - 1)) - 1] *= aNonMember;
        }
      }
    }

    st.site = &xc_emlrtRSI;
    mindim2(&st, Del, minDel, b_nidx);
    nmoved = 0;
    i17 = moved->size[0];
    moved->size[0] = n;
    emxEnsureCapacity(sp, (emxArray__common *)moved, i17, (int32_T)sizeof
                      (int32_T), &m_emlrtRTEI);
    for (i17 = 0; i17 < n; i17++) {
      moved->data[i17] = 0;
    }

    st.site = &yc_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (nidx = 1; nidx <= n; nidx++) {
      i17 = idx->size[0];
      if (!((nidx >= 1) && (nidx <= i17))) {
        emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)&wf_emlrtBCI,
          sp);
      }

      i17 = b_nidx->size[0];
      if (!((nidx >= 1) && (nidx <= i17))) {
        emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)&xf_emlrtBCI,
          sp);
      }

      if (idx->data[nidx - 1] != b_nidx->data[nidx - 1]) {
        i17 = counts->size[0];
        i18 = idx->size[0];
        if (!((nidx >= 1) && (nidx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(nidx, 1, i18, (emlrtBCInfo *)
            &ag_emlrtBCI, sp);
        }

        i18 = idx->data[nidx - 1];
        if (!((i18 >= 1) && (i18 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)&yf_emlrtBCI,
            sp);
        }

        if (counts->data[i18 - 1] != 1) {
          i17 = Del->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &bg_emlrtBCI, sp);
          }

          i17 = Del->size[1];
          i18 = idx->size[0];
          if (!((nidx >= 1) && (nidx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i18, (emlrtBCInfo *)
              &cg_emlrtBCI, sp);
          }

          i18 = idx->data[nidx - 1];
          if (!((i18 >= 1) && (i18 <= i17))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)
              &cg_emlrtBCI, sp);
          }

          i17 = minDel->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &dg_emlrtBCI, sp);
          }

          if (Del->data[(nidx + Del->size[0] * (i18 - 1)) - 1] > minDel->
              data[nidx - 1]) {
            nmoved++;
            i17 = moved->size[0];
            if (!((nmoved >= 1) && (nmoved <= i17))) {
              emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
                &eg_emlrtBCI, sp);
            }

            moved->data[nmoved - 1] = nidx;
          }
        }
      }
    }

    if (nmoved == 0) {
      if ((*iter == iter1) || (nummoved > 0)) {
        (*iter)++;
      }

      converged = true;
      exitg1 = true;
    } else {
      modmin = n;
      st.site = &ad_emlrtRSI;
      if (nmoved > 2147483646) {
        b_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (nidx = 1; nidx <= nmoved; nidx++) {
        i17 = moved->size[0];
        if (!((nidx >= 1) && (nidx <= i17))) {
          emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
            &tf_emlrtBCI, sp);
        }

        if (moved->data[nidx - 1] < lastmoved) {
          i17 = moved->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &vf_emlrtBCI, sp);
          }

          mvScalar = (n - lastmoved) + moved->data[nidx - 1];
          if (n == 0) {
          } else {
            st.site = &dd_emlrtRSI;
            mvScalar -= div_s32(&st, mvScalar, n) * n;
          }
        } else {
          i17 = moved->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &uf_emlrtBCI, sp);
          }

          mvScalar = moved->data[nidx - 1] - lastmoved;
          if (n == 0) {
          } else {
            st.site = &dd_emlrtRSI;
            mvScalar -= div_s32(&st, mvScalar, n) * n;
          }
        }

        if (mvScalar < modmin) {
          modmin = mvScalar;
        }
      }

      modmin = (modmin + lastmoved) - 1;
      if (n == 0) {
      } else {
        st.site = &dd_emlrtRSI;
        modmin -= div_s32(&st, modmin, n) * n;
      }

      guard1 = false;
      if (modmin + 1 <= lastmoved - 1) {
        (*iter)++;
        if (*iter >= 1000) {
          exitg1 = true;
        } else {
          nummoved = 0;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        nummoved++;
        lastmoved = modmin + 2;
        i17 = idx->size[0];
        if (!((modmin + 1 >= 1) && (modmin + 1 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(modmin + 1, 1, i17, (emlrtBCInfo *)
            &ef_emlrtBCI, sp);
        }

        nmoved = idx->data[modmin];
        i17 = b_nidx->size[0];
        if (!((modmin + 1 >= 1) && (modmin + 1 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(modmin + 1, 1, i17, (emlrtBCInfo *)
            &ff_emlrtBCI, sp);
        }

        nidx = b_nidx->data[modmin];
        i17 = idx->size[0];
        if (!((modmin + 1 >= 1) && (modmin + 1 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(modmin + 1, 1, i17, (emlrtBCInfo *)
            &gf_emlrtBCI, sp);
        }

        idx->data[modmin] = b_nidx->data[modmin];
        i17 = counts->size[0];
        i18 = b_nidx->data[modmin];
        if (!((i18 >= 1) && (i18 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)&hf_emlrtBCI,
            sp);
        }

        i17 = counts->size[0];
        mvScalar = b_nidx->data[modmin];
        if (!((mvScalar >= 1) && (mvScalar <= i17))) {
          emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
            &if_emlrtBCI, sp);
        }

        counts->data[mvScalar - 1] = counts->data[i18 - 1] + 1;
        i17 = counts->size[0];
        if (!((nmoved >= 1) && (nmoved <= i17))) {
          emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
            &jf_emlrtBCI, sp);
        }

        i17 = counts->size[0];
        if (!((nmoved >= 1) && (nmoved <= i17))) {
          emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
            &kf_emlrtBCI, sp);
        }

        counts->data[nmoved - 1]--;
        if (b_nidx->data[modmin] < nmoved) {
          changed->data[0] = b_nidx->data[modmin];
          changed->data[1] = nmoved;
        } else {
          changed->data[0] = nmoved;
          changed->data[1] = b_nidx->data[modmin];
        }

        nchanged = 2;
        i17 = counts->size[0];
        i18 = b_nidx->data[modmin];
        if (!((i18 >= 1) && (i18 <= i17))) {
          emlrtDynamicBoundsCheckR2012b(i18, 1, i17, (emlrtBCInfo *)&te_emlrtBCI,
            sp);
        }

        i17 = counts->size[0];
        if (!((nmoved >= 1) && (nmoved <= i17))) {
          emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
            &ue_emlrtBCI, sp);
        }

        st.site = &bd_emlrtRSI;
        if ((!(1 > p)) && (p > 2147483646)) {
          b_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (mvScalar = 1; mvScalar <= p; mvScalar++) {
          i17 = X->size[0];
          if (!((modmin + 1 >= 1) && (modmin + 1 <= i17))) {
            emlrtDynamicBoundsCheckR2012b(modmin + 1, 1, i17, (emlrtBCInfo *)
              &ve_emlrtBCI, sp);
          }

          i17 = X->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &we_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &xe_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &ye_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &lf_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &mf_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nidx >= 1) && (nidx <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nidx, 1, i17, (emlrtBCInfo *)
              &nf_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &of_emlrtBCI, sp);
          }

          C->data[(nidx + C->size[0] * (mvScalar - 1)) - 1] += (X->data[modmin +
            X->size[0] * (mvScalar - 1)] - C->data[(nidx + C->size[0] *
            (mvScalar - 1)) - 1]) / (real_T)counts->data[b_nidx->data[modmin] -
            1];
          i17 = X->size[0];
          if (!((modmin + 1 >= 1) && (modmin + 1 <= i17))) {
            emlrtDynamicBoundsCheckR2012b(modmin + 1, 1, i17, (emlrtBCInfo *)
              &af_emlrtBCI, sp);
          }

          i17 = X->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &bf_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nmoved >= 1) && (nmoved <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
              &cf_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &df_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nmoved >= 1) && (nmoved <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
              &pf_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &qf_emlrtBCI, sp);
          }

          i17 = C->size[0];
          if (!((nmoved >= 1) && (nmoved <= i17))) {
            emlrtDynamicBoundsCheckR2012b(nmoved, 1, i17, (emlrtBCInfo *)
              &rf_emlrtBCI, sp);
          }

          i17 = C->size[1];
          if (!((mvScalar >= 1) && (mvScalar <= i17))) {
            emlrtDynamicBoundsCheckR2012b(mvScalar, 1, i17, (emlrtBCInfo *)
              &sf_emlrtBCI, sp);
          }

          C->data[(nmoved + C->size[0] * (mvScalar - 1)) - 1] -= (X->data[modmin
            + X->size[0] * (mvScalar - 1)] - C->data[(nmoved + C->size[0] *
            (mvScalar - 1)) - 1]) / (real_T)counts->data[nmoved - 1];
        }
      }
    }
  }

  emxFree_int32_T(&b_nidx);
  emxFree_real_T(&minDel);
  emxFree_int32_T(&moved);
  emxFree_real_T(&Del);
  emxFree_int32_T(&changed);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return converged;
}

void kmeans(const emlrtStack *sp, emxArray_real_T *X, real_T kin, const
            emxArray_real_T *varargin_2, emxArray_real_T *idxbest)
{
  int32_T n;
  int32_T p;
  boolean_T overflow;
  emxArray_boolean_T *wasnan;
  int32_T i3;
  int32_T i;
  boolean_T hadnans;
  emxArray_int32_T *crows;
  int32_T end;
  int32_T nNonEmpty;
  boolean_T exitg1;
  emxArray_real_T *Cbest;
  emxArray_real_T *b_X;
  int32_T i4;
  int32_T i5;
  emxArray_real_T *D;
  emxArray_real_T *d;
  emxArray_int32_T *counts;
  emxArray_int32_T *nonEmpties;
  emxArray_real_T *sumD;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  n = X->size[0];
  p = X->size[1];
  if (X->size[0] >= kin) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &gb_emlrtRTEI,
      "stats:kmeans:TooManyClusters", 0);
  }

  if (((int32_T)kin > 0) && ((int32_T)kin == kin)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &fb_emlrtRTEI, "stats:kmeans:InvalidK", 0);
  }

  if ((int32_T)kin <= X->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &eb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_boolean_T(sp, &wasnan, 1, &e_emlrtRTEI, true);
  i3 = wasnan->size[0];
  wasnan->size[0] = X->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)wasnan, i3, (int32_T)sizeof
                    (boolean_T), &d_emlrtRTEI);
  i = X->size[0];
  for (i3 = 0; i3 < i; i3++) {
    wasnan->data[i3] = false;
  }

  hadnans = false;
  st.site = &l_emlrtRSI;
  overflow = ((!(1 > X->size[0])) && (X->size[0] > 2147483646));
  if (overflow) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 1; i <= n; i++) {
    st.site = &m_emlrtRSI;
    if ((!(1 > p)) && (p > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    nNonEmpty = 1;
    exitg1 = false;
    while ((!exitg1) && (nNonEmpty <= p)) {
      i3 = X->size[0];
      if (!((i >= 1) && (i <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&f_emlrtBCI, sp);
      }

      i3 = X->size[1];
      if (!((nNonEmpty >= 1) && (nNonEmpty <= i3))) {
        emlrtDynamicBoundsCheckR2012b(nNonEmpty, 1, i3, (emlrtBCInfo *)
          &e_emlrtBCI, sp);
      }

      if (muDoubleScalarIsNaN(X->data[(i + X->size[0] * (nNonEmpty - 1)) - 1]))
      {
        hadnans = true;
        i3 = wasnan->size[0];
        if (!((i >= 1) && (i <= i3))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&cb_emlrtBCI,
            sp);
        }

        wasnan->data[i - 1] = true;
        exitg1 = true;
      } else {
        nNonEmpty++;
      }
    }
  }

  emxInit_int32_T(sp, &crows, 1, &g_emlrtRTEI, true);
  if (hadnans) {
    st.site = &n_emlrtRSI;
    warning(&st);
    end = wasnan->size[0] - 1;
    nNonEmpty = 0;
    for (i = 0; i <= end; i++) {
      if (!wasnan->data[i]) {
        nNonEmpty++;
      }
    }

    i3 = crows->size[0];
    crows->size[0] = nNonEmpty;
    emxEnsureCapacity(sp, (emxArray__common *)crows, i3, (int32_T)sizeof(int32_T),
                      &d_emlrtRTEI);
    nNonEmpty = 0;
    for (i = 0; i <= end; i++) {
      if (!wasnan->data[i]) {
        crows->data[nNonEmpty] = i + 1;
        nNonEmpty++;
      }
    }

    emxInit_real_T(sp, &b_X, 2, &d_emlrtRTEI, true);
    nNonEmpty = X->size[0];
    end = X->size[1];
    i3 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = crows->size[0];
    b_X->size[1] = end;
    emxEnsureCapacity(sp, (emxArray__common *)b_X, i3, (int32_T)sizeof(real_T),
                      &d_emlrtRTEI);
    for (i3 = 0; i3 < end; i3++) {
      i = crows->size[0];
      for (i4 = 0; i4 < i; i4++) {
        i5 = crows->data[i4];
        if (!((i5 >= 1) && (i5 <= nNonEmpty))) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, nNonEmpty, (emlrtBCInfo *)
            &g_emlrtBCI, sp);
        }

        b_X->data[i4 + b_X->size[0] * i3] = X->data[(i5 + X->size[0] * i3) - 1];
      }
    }

    i3 = X->size[0] * X->size[1];
    X->size[0] = b_X->size[0];
    X->size[1] = b_X->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)X, i3, (int32_T)sizeof(real_T),
                      &d_emlrtRTEI);
    i = b_X->size[1];
    for (i3 = 0; i3 < i; i3++) {
      end = b_X->size[0];
      for (i4 = 0; i4 < end; i4++) {
        X->data[i4 + X->size[0] * i3] = b_X->data[i4 + b_X->size[0] * i3];
      }
    }

    emxFree_real_T(&b_X);
  }

  if ((int32_T)kin == varargin_2->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &db_emlrtRTEI,
      "stats:kmeans:StartBadRowSize", 0);
  }

  if (p == varargin_2->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
      "stats:kmeans:StartBadColumnSize", 0);
  }

  emxInit_real_T(sp, &Cbest, 2, &d_emlrtRTEI, true);
  st.site = &o_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  p = X->size[0];
  nNonEmpty = varargin_2->size[0];
  i = varargin_2->size[0];
  end = varargin_2->size[1];
  i3 = Cbest->size[0] * Cbest->size[1];
  Cbest->size[0] = i;
  Cbest->size[1] = end;
  emxEnsureCapacity(&b_st, (emxArray__common *)Cbest, i3, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  for (i3 = 0; i3 < end; i3++) {
    for (i4 = 0; i4 < i; i4++) {
      Cbest->data[i4 + Cbest->size[0] * i3] = varargin_2->data[i4 + nNonEmpty *
        i3];
    }
  }

  i3 = crows->size[0];
  crows->size[0] = (int32_T)kin;
  emxEnsureCapacity(&b_st, (emxArray__common *)crows, i3, (int32_T)sizeof
                    (int32_T), &d_emlrtRTEI);
  i = (int32_T)kin;
  for (i3 = 0; i3 < i; i3++) {
    crows->data[i3] = 0;
  }

  c_st.site = &r_emlrtRSI;
  if ((!(1 > (int32_T)kin)) && ((int32_T)kin > 2147483646)) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (nNonEmpty = 1; nNonEmpty <= (int32_T)kin; nNonEmpty++) {
    i3 = crows->size[0];
    if (!((nNonEmpty >= 1) && (nNonEmpty <= i3))) {
      emlrtDynamicBoundsCheckR2012b(nNonEmpty, 1, i3, (emlrtBCInfo *)
        &bb_emlrtBCI, &b_st);
    }

    crows->data[nNonEmpty - 1] = nNonEmpty;
  }

  emxInit_real_T(&b_st, &D, 2, &d_emlrtRTEI, true);
  i3 = D->size[0] * D->size[1];
  D->size[0] = X->size[0];
  D->size[1] = (int32_T)kin;
  emxEnsureCapacity(&b_st, (emxArray__common *)D, i3, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  i = X->size[0] * (int32_T)kin;
  for (i3 = 0; i3 < i; i3++) {
    D->data[i3] = 0.0;
  }

  emxInit_real_T1(&b_st, &d, 1, &f_emlrtRTEI, true);
  emxInit_int32_T(&b_st, &counts, 1, &h_emlrtRTEI, true);
  c_st.site = &s_emlrtRSI;
  distfun(&c_st, D, X, Cbest, crows, (int32_T)kin);
  c_st.site = &t_emlrtRSI;
  mindim2(&c_st, D, d, crows);
  i3 = counts->size[0];
  counts->size[0] = (int32_T)kin;
  emxEnsureCapacity(&b_st, (emxArray__common *)counts, i3, (int32_T)sizeof
                    (int32_T), &d_emlrtRTEI);
  i = (int32_T)kin;
  for (i3 = 0; i3 < i; i3++) {
    counts->data[i3] = 0;
  }

  c_st.site = &u_emlrtRSI;
  overflow = ((!(1 > X->size[0])) && (X->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 1; i <= p; i++) {
    i3 = counts->size[0];
    i4 = crows->size[0];
    if (!((i >= 1) && (i <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i4, (emlrtBCInfo *)&x_emlrtBCI, &b_st);
    }

    i4 = crows->data[i - 1];
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&w_emlrtBCI, &b_st);
    }

    i3 = counts->size[0];
    i5 = crows->size[0];
    if (!((i >= 1) && (i <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i5, (emlrtBCInfo *)&ab_emlrtBCI, &b_st);
    }

    i5 = crows->data[i - 1];
    if (!((i5 >= 1) && (i5 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i3, (emlrtBCInfo *)&y_emlrtBCI, &b_st);
    }

    counts->data[i5 - 1] = counts->data[i4 - 1] + 1;
  }

  emxInit_int32_T(&b_st, &nonEmpties, 1, &i_emlrtRTEI, true);
  i3 = nonEmpties->size[0];
  nonEmpties->size[0] = (int32_T)kin;
  emxEnsureCapacity(&b_st, (emxArray__common *)nonEmpties, i3, (int32_T)sizeof
                    (int32_T), &d_emlrtRTEI);
  i = (int32_T)kin;
  for (i3 = 0; i3 < i; i3++) {
    nonEmpties->data[i3] = 0;
  }

  c_st.site = &v_emlrtRSI;
  batchUpdate(&c_st, X, (int32_T)kin, crows, Cbest, D, counts, &overflow,
              &nNonEmpty);
  if ((int32_T)kin >= 2) {
    c_st.site = &w_emlrtRSI;
    overflow = onlineUpdate(&c_st, X, (int32_T)kin, crows, Cbest, counts,
      &nNonEmpty);
  }

  if (!overflow) {
    c_st.site = &x_emlrtRSI;
    b_warning(&c_st);
  }

  nNonEmpty = 0;
  c_st.site = &y_emlrtRSI;
  if ((!(1 > (int32_T)kin)) && ((int32_T)kin > 2147483646)) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 1; i <= (int32_T)kin; i++) {
    i3 = counts->size[0];
    if (!((i >= 1) && (i <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&u_emlrtBCI, &b_st);
    }

    if (counts->data[i - 1] > 0) {
      nNonEmpty++;
      i3 = nonEmpties->size[0];
      if (!((nNonEmpty >= 1) && (nNonEmpty <= i3))) {
        emlrtDynamicBoundsCheckR2012b(nNonEmpty, 1, i3, (emlrtBCInfo *)
          &v_emlrtBCI, &b_st);
      }

      nonEmpties->data[nNonEmpty - 1] = i;
    }
  }

  emxFree_int32_T(&counts);
  c_st.site = &ab_emlrtRSI;
  distfun(&c_st, D, X, Cbest, nonEmpties, nNonEmpty);
  c_st.site = &bb_emlrtRSI;
  emxFree_real_T(&Cbest);
  overflow = ((!(1 > X->size[0])) && (X->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 1; i <= p; i++) {
    i3 = D->size[0];
    if (!(i <= i3)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&r_emlrtBCI, &b_st);
    }

    i3 = D->size[1];
    i4 = crows->size[0];
    if (!(i <= i4)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i4, (emlrtBCInfo *)&s_emlrtBCI, &b_st);
    }

    i4 = crows->data[i - 1];
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&s_emlrtBCI, &b_st);
    }

    i3 = d->size[0];
    if (!(i <= i3)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&t_emlrtBCI, &b_st);
    }

    d->data[i - 1] = D->data[(i + D->size[0] * (i4 - 1)) - 1];
  }

  emxFree_real_T(&D);
  emxInit_real_T1(&b_st, &sumD, 1, &j_emlrtRTEI, true);
  i3 = sumD->size[0];
  sumD->size[0] = (int32_T)kin;
  emxEnsureCapacity(&b_st, (emxArray__common *)sumD, i3, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  i = (int32_T)kin;
  for (i3 = 0; i3 < i; i3++) {
    sumD->data[i3] = 0.0;
  }

  c_st.site = &cb_emlrtRSI;
  overflow = ((!(1 > X->size[0])) && (X->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 1; i <= p; i++) {
    i3 = sumD->size[0];
    i4 = crows->size[0];
    if (!(i <= i4)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i4, (emlrtBCInfo *)&n_emlrtBCI, &b_st);
    }

    i4 = crows->data[i - 1];
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&m_emlrtBCI, &b_st);
    }

    i3 = d->size[0];
    if (!(i <= i3)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&o_emlrtBCI, &b_st);
    }

    i3 = sumD->size[0];
    i5 = crows->size[0];
    if (!(i <= i5)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i5, (emlrtBCInfo *)&q_emlrtBCI, &b_st);
    }

    i5 = crows->data[i - 1];
    if (!((i5 >= 1) && (i5 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i3, (emlrtBCInfo *)&p_emlrtBCI, &b_st);
    }

    sumD->data[i5 - 1] = sumD->data[i4 - 1] + d->data[i - 1];
  }

  emxFree_real_T(&d);
  c_st.site = &db_emlrtRSI;
  if ((!(1 > nNonEmpty)) && (nNonEmpty > 2147483646)) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (i = 1; i <= nNonEmpty; i++) {
    i3 = sumD->size[0];
    i4 = nonEmpties->size[0];
    if (!((i >= 1) && (i <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i4, (emlrtBCInfo *)&l_emlrtBCI, &b_st);
    }

    i4 = nonEmpties->data[i - 1];
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&d_emlrtBCI, &b_st);
    }
  }

  emxFree_real_T(&sumD);
  emxFree_int32_T(&nonEmpties);
  if (hadnans) {
    i3 = idxbest->size[0];
    idxbest->size[0] = n;
    emxEnsureCapacity(sp, (emxArray__common *)idxbest, i3, (int32_T)sizeof
                      (real_T), &d_emlrtRTEI);
    for (i3 = 0; i3 < n; i3++) {
      idxbest->data[i3] = 0.0;
    }

    nNonEmpty = 0;
    st.site = &p_emlrtRSI;
    for (i = 1; i <= n; i++) {
      i3 = wasnan->size[0];
      if (!(i <= i3)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&h_emlrtBCI, sp);
      }

      if (wasnan->data[i - 1]) {
        i3 = idxbest->size[0];
        if (!(i <= i3)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&k_emlrtBCI, sp);
        }

        idxbest->data[i - 1] = rtNaN;
      } else {
        nNonEmpty++;
        i3 = crows->size[0];
        if (!((nNonEmpty >= 1) && (nNonEmpty <= i3))) {
          emlrtDynamicBoundsCheckR2012b(nNonEmpty, 1, i3, (emlrtBCInfo *)
            &i_emlrtBCI, sp);
        }

        i3 = idxbest->size[0];
        if (!(i <= i3)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i3, (emlrtBCInfo *)&j_emlrtBCI, sp);
        }

        idxbest->data[i - 1] = crows->data[nNonEmpty - 1];
      }
    }
  } else {
    i3 = idxbest->size[0];
    idxbest->size[0] = crows->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)idxbest, i3, (int32_T)sizeof
                      (real_T), &d_emlrtRTEI);
    i = crows->size[0];
    for (i3 = 0; i3 < i; i3++) {
      idxbest->data[i3] = crows->data[i3];
    }
  }

  emxFree_int32_T(&crows);
  emxFree_boolean_T(&wasnan);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (kmeans.cpp) */
