#ifndef foovolumeproxyhfoo
#define foovolumeproxyhfoo

/***
  This file is copied from PulseAudio (the version used in MeeGo 1.2
  Harmattan).

  Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation; either version 2.1 of the License,
  or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

/* This library is mainly used by stream-restore module to forward
 * it's current route stream volumes.
 * When other clients use pa_volume_proxy_set_volume, volume is applied
 * to stream-restore volume database IF volume entry with same stream
 * name already exists in the database.
 */

#include <pulsecore/core.h>
#include <pulsecore/hook-list.h>
#include <pulse/volume.h>

typedef struct pa_volume_proxy pa_volume_proxy;

/* Hook data: pa_volume_proxy pointer. */
typedef enum pa_volume_proxy_hook {
    PA_VOLUME_PROXY_HOOK_CHANGED, /* Call data: const char* stream_name */
    PA_VOLUME_PROXY_HOOK_MAX
} pa_volume_proxy_hook_t;

pa_volume_proxy *pa_volume_proxy_get(pa_core *core);
pa_volume_proxy *pa_volume_proxy_ref(pa_volume_proxy *r);
void pa_volume_proxy_unref(pa_volume_proxy *r);

void pa_volume_proxy_set_volume(pa_volume_proxy *r, const char *name, pa_volume_t volume);

/* return TRUE if volume was found from proxy database,
 * otherwise return FALSE. The value of volume is returned
 * in return_volume. */
pa_bool_t pa_volume_proxy_get_volume(pa_volume_proxy *r, const char *name, pa_volume_t *return_volume);

pa_hook *pa_volume_proxy_hooks(pa_volume_proxy *r);

#endif
