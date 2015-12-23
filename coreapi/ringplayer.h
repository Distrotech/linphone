/*
linphone
Copyright (C) 2000 - 2010 Simon MORLAT (simon.morlat@linphone.org)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef RINGPLAYER_H
#define RINGPLAYER_H

#include "linphonecore.h"

typedef struct _LinphoneRingPlayer {
	RingStream *ringstream;
} LinphoneRingPlayer;

LinphoneRingPlayer* linphone_ringplayer_new();
void linphone_ringplayer_destroy(LinphoneRingPlayer* rp);

int linphone_ringplayer_start(LinphoneRingPlayer* rp, MSSndCard* card, const char* ring, int loop_pause_ms);
int linphone_ringplayer_start_with_cb(LinphoneRingPlayer* rp, MSSndCard* card, const char* ring, int loop_pause_ms, MSFilterNotifyFunc func, void * user_data);
bool_t linphone_ringplayer_is_started(LinphoneRingPlayer* rp);
int linphone_ringplayer_stop(LinphoneRingPlayer* rp);

#endif
