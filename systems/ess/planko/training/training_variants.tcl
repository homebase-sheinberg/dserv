#
# VARIANTS
#   planko training
#
# DESCRIPTION
#   variant dictionary
#

namespace eval planko::training {
    package require planko
    
    variable basic_planko_defaults    { nr 100  params {} }
    variable params_defaults          { n_rep 50 }

    variable basic_planko_single      { nr 100 nplanks 1 }
    variable basic_planko_jitter      { nr 50 nplanks 1 params \
					    { ball_jitter_x 8 ball_start_y 5 ball_jitter_y 1 } }
    
    variable variants {
	single      { basic_planko single    "one plank"}
	jitter      { basic_planko jitter    "jitter ball start"}
    }	

    proc variants_init { s } {
	
	$s add_method single_init {} {
	    rmtSend "setBackground 10 10 10"
	}
	$s add_method single_deinit {} {}
	
	$s add_method basic_planko { nr nplanks params } {
	    set n_rep $nr
	    
	    if { [dg_exists stimdg] } { dg_delete stimdg }

	    
	    set n_obs [expr [llength $nplanks]*$n_rep]
	    
	    set maxx [expr $screen_halfx]
	    set maxy [expr $screen_halfy]

	    # this is a set of params to pass into generate_worlds
	    set p "nplanks $nplanks $params"
	    set g [planko::generate_worlds $n_obs $p]

	    # rename id column to stimtytpe
	    dg_rename $g:id stimtype 
	    dl_set $g:remaining [dl_ones $n_obs]
	    
	    dg_rename $g stimdg
	    return $g
	}
    }
}

