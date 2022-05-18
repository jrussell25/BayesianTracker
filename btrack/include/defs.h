/*
--------------------------------------------------------------------------------
 Name:     BayesianTracker
 Purpose:  A multi object tracking library, specifically used to reconstruct
           tracks in crowded fields. Here we use a probabilistic network of
           information to perform the trajectory linking. This method uses
           positional and visual information for track linking.

 Authors:  Alan R. Lowe (arl) a.lowe@ucl.ac.uk

 License:  See LICENSE.md

 Created:  14/08/2014
--------------------------------------------------------------------------------
*/

#ifndef _DEFS_H_INCLUDED_
#define _DEFS_H_INCLUDED_

#include <iostream>
#include <limits>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// store some information about the compilation
static unsigned int v_major = VERSION_MAJOR;
static unsigned int v_minor = VERSION_MINOR;
static unsigned int v_build = VERSION_BUILD;
static std::string build_date = __DATE__;
static std::string build_time = __TIME__;

// errors
#define SUCCESS 900
#define ERROR_empty_queue 901
#define ERROR_no_tracks 902
#define ERROR_no_useable_frames 903
#define ERROR_track_empty 904
#define ERROR_incorrect_motion_model 905
#define ERROR_max_lost_out_of_range 906
#define ERROR_accuracy_out_of_range 907
#define ERROR_prob_not_assign_out_of_range 908
#define ERROR_not_defined 909
#define ERROR_none 910

// constants
const double kInfinity = std::numeric_limits<double>::infinity();

// constants for integrating Gaussian PDF
const double kRootTwo = std::sqrt(2.0);
const double kRootTwoPi = std::sqrt(2.0*M_PI);

// tracking params
#define PROB_NOT_ASSIGN 0.01
#define DEFAULT_ACCURACY 2.0
#define DISALLOW_METAPHASE_ANAPHASE_LINKING true
#define DISALLOW_PROMETAPHASE_ANAPHASE_LINKING true
#define SPLIT_INCORRECTLY_JOINED_TRACKS true
#define PROB_ASSIGN_EXP_DECAY true
#define DYNAMIC_ACCURACY false
#define DIMS 3
#define MAX_LOST 5
#define MAX_SEARCH_RADIUS 100
#define WRITE_BELIEF_MATRIX false
#define RESOLVE_CONFLICTS true
#define CLIP_MAXIMUM_LINKAGE_DISTANCE true


// reserve space for objects and tracks
#define RESERVE_NEW_OBJECTS 1000
#define RESERVE_ACTIVE_TRACKS 1000

// possible states of objects
#define STATE_interphase 0
#define STATE_prometaphase 1
#define STATE_metaphase 2
#define STATE_anaphase 3
#define STATE_apoptosis 4
#define STATE_null 5
#define STATE_dummy 99

// hypothesis and state types
// ['P_FP','P_init','P_term','P_link','P_branch','P_dead','P_merge']
#define TYPE_Pfalse       0
#define TYPE_Pinit        1
#define TYPE_Pterm        2
#define TYPE_Plink        3
#define TYPE_Pdivn        4
#define TYPE_Papop        5
#define TYPE_Pmrge        6
#define TYPE_Pextr        7
#define TYPE_Pinit_border 10
#define TYPE_Pinit_front  11
#define TYPE_Pinit_lazy   12
#define TYPE_Pterm_border 20
#define TYPE_Pterm_back   21
#define TYPE_Pterm_lazy   22
#define TYPE_Pdead        666
#define TYPE_undef        999

// update methods
#define UPDATE_MODE_EXACT 0
#define UPDATE_MODE_APPROXIMATE 1
#define UPDATE_MODE_CUDA 2


// hypothesis generation
#define MAX_TRACK_LEN 150
#define DEFAULT_LOW_PROBABILITY 1e-308
#define DEFAULT_LOST_PROBABILITY 0.1
#define WEIGHT_METAPHASE_ANAPHASE_ANAPHASE 0.01
#define WEIGHT_METAPHASE_ANAPHASE 0.1
#define WEIGHT_METAPHASE 2.0
#define WEIGHT_ANAPHASE_ANAPHASE 1.0
#define WEIGHT_ANAPHASE 2.0
#define WEIGHT_OTHER 5.0
#define PENALTY_METAPHASE_ANAPHASE_LINKING 10.0
#define PENALTY_PROMETAPHASE_ANAPHASE_LINKING 10.0

// definitions to use for countins states in the hypothesis engine
#define COUNT_STATE_FROM_BACK true
#define COUNT_STATE_FROM_FRONT false

// flag for defining apoptosis
// setting this to true means that the p_apoptosis scales with the absolute
// numer of apoptotic counts, if set to false, the algorithm uses the fraction
// of the length of the tracklet that is apoptotic
#define USE_ABSOLUTE_APOPTOSIS_COUNTS true


// flag to use a uniform prior
#define USE_UNIFORM_PRIOR true
#define USE_CURRENT_PRIOR false


#endif
