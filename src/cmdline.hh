/* Copyright (c) 2017 The Board of Trustees of the University of Illinois
 * All rights reserved.
 *
 * Developed by: National Center for Supercomputing Applications
 *               University of Illinois at Urbana-Champaign
 *               http://www.ncsa.illinois.edu/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimers.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimers in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the names of the National Center for Supercomputing Applications,
 * University of Illinois at Urbana-Champaign, nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * Software without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.  */

#ifndef CMDLINE_HH_
#define CMDLINE_HH_

#include <string>
#include "fileentry.hh"

class cmdline
{
  public:
  cmdline(const int argc, char * const argv[], bool mute);
  ~cmdline() {};

  // action is one of [cxt] or [e] for a immediate regular exit or [E] for an
  // error exit
  enum action { ACTION_INVALID=0, ACTION_EXIT='e', ACTION_ERROR='E',
                ACTION_CREATE='c' };
  action get_action() const { return action; };
  fileentries& get_fileentries() { return entries; };
  const std::string &get_tarfilename() const { return tarfilename; };

  private:
  action action;
  fileentries entries;
  std::string tarfilename;
};

#endif // CMDLINE_HH_
