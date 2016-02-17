/**
 * This file is part of RagEmu.
 * http://ragemu.org - https://github.com/RagEmu/Renewal
 *
 * Copyright (C) 2016  RagEmu Dev Team
 * Copyright (C) 2012-2015  Hercules Dev Team
 * Copyright (C)  rAthena Project
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
#ifndef COMMON_MUTEX_H
#define COMMON_MUTEX_H

#include "common/ragemu.h"

typedef struct ramutex ramutex; // Mutex
typedef struct racond racond; // Condition Var

struct mutex_interface {
	/**
	 * Creates a Mutex
	 *
	 * @return The created mutex.
	 */
	ramutex *(*create) (void);

	/**
	 * Destroys a Mutex.
	 *
	 * @param m the mutex to destroy.
	 */
	void (*destroy) (ramutex *m);

	/**
	 * Gets a lock.
	 *
	 * @param m The mutex to lock.
	 */
	void (*lock) (ramutex *m);

	/**
	 * Tries to get a lock.
	 *
	 * @param m The mutex to try to lock.
	 * @return success status.
	 * @retval true if the lock was acquired.
	 * @retval false if the mutex couldn't be locked.
	 */
	bool (*trylock) (ramutex *m);

	/**
	 * Unlocks a mutex.
	 *
	 * @param m The mutex to unlock.
	 */
	void (*unlock) (ramutex *m);


	/**
	 * Creates a Condition variable.
	 *
	 * @return the created condition variable.
	 */
	racond *(*cond_create) (void);

	/**
	 * Destroys a Condition variable.
	 *
	 * @param c the condition variable to destroy.
	 */
	void (*cond_destroy) (racond *c);

	/**
	 * Waits Until state is signaled.
	 *
	 * @param c             The condition var to wait for signaled state.
	 * @param m             The mutex used for synchronization.
	 * @param timeout_ticks Timeout in ticks (-1 = INFINITE)
	 */
	void (*cond_wait) (racond *c, ramutex *m, sysint timeout_ticks);

	/**
	 * Sets the given condition var to signaled state.
	 *
	 * @remark
	 *   Only one waiter gets notified.
	 *
	 * @param c Condition var to set in signaled state.
	 */
	void (*cond_signal) (racond *c);

	/**
	 * Sets notifies all waiting threads thats signaled.
	 *
	 * @remark
	 *   All Waiters getting notified.
	 *
	 * @param c Condition var to set in signaled state.
	 */
	void (*cond_broadcast) (racond *c);
};

#ifdef RAGEMU_CORE
void mutex_defaults(void);
#endif // RAGEMU_CORE

HPShared struct mutex_interface *mutex;

#endif /* COMMON_MUTEX_H */
