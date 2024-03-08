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

// RUN: %oss-compile-and-run
// RUN: %oss-O2-compile-and-run
// XFAIL: *

/*
<testinfo>
test_generator=(config/mercurium-ompss "config/mercurium-ompss-2 openmp-compatibility")
test_CFLAGS="--no-copy-deps"
</testinfo>
*/

#include<assert.h>

void foo()
{
    int x = 0, y = 2;

    #pragma oss task depend(inout: x) shared(x)
    x++;

    #pragma oss task depend(in: x) depend(inout: y) shared(x, y)
    y -= x;

    #pragma oss taskwait depend(inout: x)
    assert(x == 1);
    assert(x == y);
}

int main(int argc, char*argv)
{
    foo();
    return 0;
}
