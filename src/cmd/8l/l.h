// Inferno utils/8l/l.h
// http://code.google.com/p/inferno-os/source/browse/utils/8l/l.h
//
//	Copyright © 1994-1999 Lucent Technologies Inc.  All rights reserved.
//	Portions Copyright © 1995-1997 C H Forsyth (forsyth@terzarima.net)
//	Portions Copyright © 1997-1999 Vita Nuova Limited
//	Portions Copyright © 2000-2007 Vita Nuova Holdings Limited (www.vitanuova.com)
//	Portions Copyright © 2004,2006 Bruce Ellis
//	Portions Copyright © 2005-2007 C H Forsyth (forsyth@terzarima.net)
//	Revisions Copyright © 2000-2007 Lucent Technologies Inc. and others
//	Portions Copyright © 2009 The Go Authors.  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include	<u.h>
#include	<libc.h>
#include	<bio.h>
#include	<link.h>
#include	"8.out.h"

#ifndef	EXTERN
#define	EXTERN	extern
#endif

enum
{
	thechar = '8',
	PtrSize = 4,
	IntSize = 4,
	RegSize = 4,
	MaxAlign = 32,	// max data alignment
	FuncAlign = 16
};

#define	P		((Prog*)0)
#define	S		((LSym*)0)
#define	TNAME		(ctxt->cursym?ctxt->cursym->name:noname)

enum
{
	MINSIZ		= 4,
	STRINGSZ	= 200,
	MINLC		= 1,
	MAXIO		= 8192,
	MAXHIST		= 40,				/* limit of path elements for history symbols */
};

#pragma	varargck	type	"I"	uchar*

EXTERN	LSym*	datap;
EXTERN	int	debug[128];
EXTERN	char	literal[32];
EXTERN	Prog*	firstp;
EXTERN	int32	lcsize;
EXTERN	char*	rpath;
EXTERN	int32	spsize;
EXTERN	LSym*	symlist;
EXTERN	int32	symsize;
EXTERN	int32	textsize;

int	Iconv(Fmt *fp);
void	adddynlib(char *lib);
void	adddynrel(LSym *s, Reloc *r);
void	adddynrela(LSym *rela, LSym *s, Reloc *r);
void	adddynsym(Link *ctxt, LSym *s);
int	archreloc(Reloc *r, LSym *s, vlong *val);
void	asmb(void);
int	elfreloc1(Reloc *r, vlong sectoff);
void	elfsetupplt(void);
void	listinit(void);
int	machoreloc1(Reloc *r, vlong sectoff);
void	main(int argc, char *argv[]);
int32	rnd(int32 v, int32 r);
void	s8put(char *n);
char*	xsymname(LSym *s);

/* Native is little-endian */
#define	LPUT(a)	lputl(a)
#define	WPUT(a)	wputl(a)
#define	VPUT(a)	vputl(a)

/* Used by ../ld/dwarf.c */
enum
{
	DWARFREGSP = 4
};
