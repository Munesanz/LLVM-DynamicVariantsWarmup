/*--------------------------------------------------------------------
  (C) Copyright 2006-2013 Barcelona Supercomputing Center
                          Centro Nacional de Supercomputacion

  This file is part of Mercurium C/C++ source-to-source compiler.

  See AUTHORS file in the top level directory for information
  regarding developers and contributors.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  Mercurium C/C++ source-to-source compiler is distributed in the hope
  that it will be useful, but WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public
  License along with Mercurium C/C++ source-to-source compiler; if
  not, write to the Free Software Foundation, Inc., 675 Mass Ave,
  Cambridge, MA 02139, USA.
--------------------------------------------------------------------*/

// RUN: %oss-cxx-compile-and-run
// RUN: %oss-cxx-O2-compile-and-run

// Test if the RT keeps alive outer task non-pod data until
// inner task finishes

#include <assert.h>

struct S {
    enum {
        NOT_INITIALIZED = -1,
        ALIVE = 0,
        DEAD = 1
    };
    int x = NOT_INITIALIZED;
    S() : x(ALIVE) {}
    ~S() { x = DEAD; }
};

int main() {
    S s;
    #pragma oss task firstprivate(s)
    {
        #pragma oss task shared(s) // Points to parent's data
        {
            assert(s.x == 0);
        }
    }
    #pragma oss taskwait
}
