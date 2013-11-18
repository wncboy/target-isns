/*
 * This file is part of target-isns.
 *
 * Copyright (C) 2013 Christophe Vu-Brugier <cvubrugier@yahoo.fr>
 *
 * target-isns is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * target-isns is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with target-isns; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef __CONFIGFS_H__
#define __CONFIGFS_H__

#include <linux/limits.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <ccan/list/list.h>

struct target {
	struct list_node list;
	char name[256];
	struct list_head tpgs;
	bool updated;
	int watch_fd;
};

bool configfs_iscsi_path_exists(void);

int configfs_init(void);

void configfs_cleanup(void);

void configfs_handle_events(void);

#endif
