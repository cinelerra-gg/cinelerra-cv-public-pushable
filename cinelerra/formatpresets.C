#include "edl.h"
#include "edlsession.h"
#include "formatpresets.h"
#include "new.h"
#include "setformat.h"





FormatPresets::FormatPresets(MWindow *mwindow,
	NewWindow *new_gui, 
	SetFormatWindow *format_gui, 
	int x, 
	int y)
{
	this->mwindow = mwindow;
	this->new_gui = new_gui;
	this->format_gui = format_gui;
	gui_base = new_gui ? (BC_WindowBase*)new_gui : (BC_WindowBase*)(format_gui);
	this->x = x;
	this->y = y;
	text = 0;
	pulldown = 0;
}

FormatPresets::~FormatPresets()
{
	if(text) delete text;
	if(pulldown) delete pulldown;
	for(int i = 0; i < preset_items.total; i++)
		delete preset_items.values[i];
}

void FormatPresets::create_objects()
{
// Create preset items
	FormatPresetItem *item;
	item = new FormatPresetItem(mwindow, this, _("User Defined"));
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("1080P"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)60000.0 / 1001;
// 	item->edl->session->track_w = 1920;
// 	item->edl->session->track_h = 1080;
	item->edl->session->output_w = 1920;
	item->edl->session->output_h = 1080;
	item->edl->session->aspect_w = 16;
	item->edl->session->aspect_h = 9;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("1080I"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)30000.0 / 1001;
// 	item->edl->session->track_w = 1920;
// 	item->edl->session->track_h = 1080;
	item->edl->session->output_w = 1920;
	item->edl->session->output_h = 1080;
	item->edl->session->aspect_w = 16;
	item->edl->session->aspect_h = 9;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("720P"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)60000.0 / 1001;
// 	item->edl->session->track_w = 1280;
// 	item->edl->session->track_h = 720;
	item->edl->session->output_w = 1280;
	item->edl->session->output_h = 720;
	item->edl->session->aspect_w = 16;
	item->edl->session->aspect_h = 9;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("480P"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)60000.0 / 1001;
// 	item->edl->session->track_w = 720;
// 	item->edl->session->track_h = 480;
	item->edl->session->output_w = 720;
	item->edl->session->output_h = 480;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("480I"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)30000.0 / 1001;
// 	item->edl->session->track_w = 720;
// 	item->edl->session->track_h = 480;
	item->edl->session->output_w = 720;
	item->edl->session->output_h = 480;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("Half D-1 NTSC"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = (double)30000.0 / 1001;
// 	item->edl->session->track_w = 360;
// 	item->edl->session->track_h = 240;
	item->edl->session->output_w = 360;
	item->edl->session->output_h = 240;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("Internet"));
	item->edl->session->audio_channels = 1;
	item->edl->session->audio_tracks = 1;
	item->edl->session->sample_rate = 22050;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 1;
	item->edl->session->frame_rate = 15;
// 	item->edl->session->track_w = 320;
// 	item->edl->session->track_h = 240;
	item->edl->session->output_w = 320;
	item->edl->session->output_h = 240;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("CD Audio"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 44100;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 0;
	item->edl->session->frame_rate = (double)30000.0 / 1001;
// 	item->edl->session->track_w = 720;
// 	item->edl->session->track_h = 480;
	item->edl->session->output_w = 720;
	item->edl->session->output_h = 480;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);

	item = new FormatPresetItem(mwindow, this, _("DAT Audio"));
	item->edl->session->audio_channels = 2;
	item->edl->session->audio_tracks = 2;
	item->edl->session->sample_rate = 48000;
	item->edl->session->video_channels = 1;
	item->edl->session->video_tracks = 0;
	item->edl->session->frame_rate = (double)30000.0 / 1001;
// 	item->edl->session->track_w = 720;
// 	item->edl->session->track_h = 480;
	item->edl->session->output_w = 720;
	item->edl->session->output_h = 480;
	item->edl->session->aspect_w = 4;
	item->edl->session->aspect_h = 3;
	preset_items.append(item);



	gui_base->add_subwindow(new BC_Title(x, y, _("Presets:")));
	int x1 = x;
	y += 20;


	gui_base->add_subwindow(text = new FormatPresetsText(mwindow, 
		this, 
		x, 
		y));
	x += text->get_w();
	gui_base->add_subwindow(pulldown = new FormatPresetsPulldown(mwindow, 
		this, 
		x, 
		y));
	x = x1;
}

FormatPresetItem* FormatPresets::find_preset(EDL *edl)
{
	for(int i = 1; i < preset_items.total; i++)
	{
		FormatPresetItem *preset = preset_items.values[i];
		if(edl->session->audio_tracks == preset->edl->session->audio_tracks &&
			edl->session->audio_channels == preset->edl->session->audio_channels &&
			edl->session->sample_rate == preset->edl->session->sample_rate &&
			edl->session->video_tracks == preset->edl->session->video_tracks &&
			edl->session->frame_rate == preset->edl->session->frame_rate &&
			edl->session->output_w == preset->edl->session->output_w &&
			edl->session->output_h == preset->edl->session->output_h &&
			edl->session->aspect_w == preset->edl->session->aspect_w &&
			edl->session->aspect_h == preset->edl->session->aspect_h)
		{
			return preset;
		}
	}
	return 0;
}

char* FormatPresets::get_preset_text(EDL *edl)
{
	FormatPresetItem *item = find_preset(edl);
	if(item) 
		return item->get_text();
	else
		return "Custom";
}


int FormatPresets::handle_event()
{
	return 0;
}

EDL* FormatPresets::get_edl()
{
	return 0;
}





FormatPresetsText::FormatPresetsText(MWindow *mwindow, 
	FormatPresets *gui,
	int x, 
	int y)
 : BC_TextBox(x, 
 	y, 
	200, 
	1, 
	gui->get_preset_text(gui->get_edl()))
{
	this->gui =  gui;
	this->mwindow = mwindow;
}

int FormatPresetsText::handle_event()
{
	return 1;
}










FormatPresetsPulldown::FormatPresetsPulldown(MWindow *mwindow, 
	FormatPresets *gui, 
	int x, 
	int y)
 : BC_ListBox(x, 
		y, 
		200, 
		200,
		LISTBOX_TEXT,                   // Display text list or icons
		(ArrayList<BC_ListBoxItem*>*)&gui->preset_items, // Each column has an ArrayList of BC_ListBoxItems.
		0,             // Titles for columns.  Set to 0 for no titles
		0,                // width of each column
		1,                      // Total columns.
		0,                    // Pixel of top of window.
		1)
{
	this->mwindow = mwindow;
	this->gui = gui;
}

int FormatPresetsPulldown::handle_event()
{
	gui->handle_event();
	FormatPresetItem *preset = ((FormatPresetItem*)get_selection(0, 0));
	gui->get_edl()->copy_all(preset->edl);
	gui->text->update(preset->get_text());
	gui->handle_event();
	return 1;
}

FormatPresetItem::FormatPresetItem(MWindow *mwindow, 
	FormatPresets *gui, 
	char *text)
 : BC_ListBoxItem(text)
{
	this->mwindow = mwindow;
	this->gui = gui;
	edl = new EDL;
	edl->create_objects();
	edl->copy_all(gui->get_edl());
}

FormatPresetItem::~FormatPresetItem()
{
	delete edl;
}

