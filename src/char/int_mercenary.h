/**
 * This file is part of RagEmu.
 * http://ragemu.org - https://github.com/RagEmu/Renewal
 *
 * Copyright (C) 2016  RagEmu Dev Team
 * Copyright (C) 2012-2015  Hercules Dev Team
 * Copyright (C)  Athena Dev Teams
 *
 * RagEmu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CHAR_INT_MERCENARY_H
#define CHAR_INT_MERCENARY_H

#include "common/ragemu.h"

struct mmo_charstatus;

/**
 * inter_mercenary interface
 **/
struct inter_mercenary_interface {
	bool (*owner_fromsql) (int char_id, struct mmo_charstatus *status);
	bool (*owner_tosql) (int char_id, struct mmo_charstatus *status);
	bool (*owner_delete) (int char_id);
	int (*sql_init) (void);
	void (*sql_final) (void);
	int (*parse_frommap) (int fd);
};

#ifdef RAGEMU_CORE
void inter_mercenary_defaults(void);
#endif // RAGEMU_CORE

HPShared struct inter_mercenary_interface *inter_mercenary;

#endif /* CHAR_INT_MERCENARY_H */
