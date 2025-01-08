// generated by Fast Light User Interface Designer (fluid) version 1.0401

#ifndef setup_ui_h
#define setup_ui_h
#include <FL/Fl.H>
#include "Fl_Console.h"
#include "Fl_DgFile.h"
#include "Fl_DgTable.h"
#include "Fl_PerfTable.h"
#include "Cgwin.hpp"
#include "essgui.h"
#include "EyeTouchWin.hpp"
#include "VirtualEye.hpp"
#include "Fl_OpDesk.h"
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *main_window;
#include <FL/Fl_Group.H>
#include <FL/Fl_Flex.H>
#include <FL/Fl_Button.H>
extern void refresh_cb(Fl_Button*, void*);
#include <FL/Fl_Output.H>
extern Fl_Output *sysname_widget;
extern Fl_Output *sysos_widget;
#include <FL/Fl_Tree.H>
extern void host_cb(Fl_Tree*, void*);
extern Fl_Tree *host_widget;
#include <FL/Fl_Choice.H>
extern Fl_Choice *subject_widget;
extern Fl_Output *system_status_widget;
extern Fl_Output *obscount_widget;
#include <FL/Fl_Box.H>
extern Fl_Box *obs_widget;
extern Fl_Choice *system_widget;
extern Fl_Choice *protocol_widget;
extern Fl_Choice *variant_widget;
#include <FL/Fl_Scroll.H>
extern Fl_Scroll *options_widget;
extern Fl_Scroll *settings_widget;
#include <FL/Fl_Tabs.H>
extern EyeTouchWin *eyetouch_widget;
extern Fl_Flex *sorters_widget;
extern void sortby_cb(Fl_Choice*, void*);
extern Fl_Choice *sortby_1;
extern Fl_Choice *sortby_2;
extern PerfTable *perftable_widget;
extern PerfTable *general_perf_widget;
extern Fl_Group *plot_widget;
extern CGWin *cgwin_widget;
extern void virtual_eye_cb(VirtualEye*, void*);
extern VirtualEye *virtual_eye_widget;
extern Fl_Scroll *rmt_commands_widget;
extern DGTable *stimdg_widget;
extern Fl_OpDesk *opdesk_widget;
extern Fl_Tabs *editor_tabs;
#include <FL/Fl_Text_Editor.H>
extern Fl_Text_Editor *system_editor;
extern Fl_Text_Editor *protocol_editor;
extern Fl_Text_Editor *variant_editor;
extern Fl_Text_Editor *stim_editor;
extern Fl_Console *output_term;
extern Fl_Output *status_widget;
Fl_Double_Window * setup_ui(int argc, char *argv[]);
#endif
