#    This file is part of the RMAP software
#
#    Copyright (C) 2008 Cold Spring Harbor Laboratory, 
#                       University of Southern California and
#                       Andrew D. Smith
#
#    Authors: Andrew D. Smith
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

RMAP = $(shell pwd)

BINDIR = $(RMAP)/bin

all:
	@make -C src RMAP=$(RMAP) OPT=1

install:
	@make -C src RMAP=$(RMAP) OPT=1 install

test:
	@make -C src RMAP=$(RMAP) test
.PHONY: test

clean:
	@make -C src RMAP=$(RMAP) clean
.PHONY: clean

distclean: clean
	@rm -rf $(RMAP)/bin
	@rm -rf $(RMAP)/lib
	@rm -rf $(RMAP)/include
.PHONY: distclean
