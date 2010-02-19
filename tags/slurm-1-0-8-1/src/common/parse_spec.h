/*****************************************************************************\
 * parse_spec.h - header for parser parse_spec.c
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Morris Jette <jette1@llnl.gov>
 *  UCRL-CODE-217948.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#ifndef _SLURM_PARSE_H_
#define	_SLURM_PARSE_H_

#if HAVE_CONFIG_H
#  include "config.h"
#  if HAVE_INTTYPES_H
#    include <inttypes.h>
#  else
#    if HAVE_STDINT_H
#      include <stdint.h>
#    endif
#  endif  /* HAVE_INTTYPES_H */
#else	/* !HAVE_CONFIG_H */
#  include <inttypes.h>
#endif  /*  HAVE_CONFIG_H */

/* 
 * slurm_parser - parse the supplied specification into keyword/value pairs
 *	only the keywords supplied will be searched for. the supplied 
 *	specification is altered, overwriting the keyword and value pairs 
 *	with spaces.
 * spec - pointer to the string of specifications, sets of three values 
 *	(as many sets as required): keyword, type, value 
 * IN keyword - string with the keyword to search for including equal sign 
 *		(e.g. "name=")
 * IN type - char with value 'd'==int, 'f'==float, 's'==string, 'l'==long
 * IN/OUT value - pointer to storage location for value (char **) for type 's'
 * RET 0 if no error, otherwise errno code
 * NOTE: terminate with a keyword value of "END"
 * NOTE: values of type (char *) are xfreed if non-NULL. caller must xfree any 
 *	returned value
 */
extern int slurm_parser (char *spec, ...) ;

/*
 * load_string  - parse a string for a keyword, value pair, and load the 
 *	char value
 * IN/OUT destination - location into which result is stored, set to value, 
 *	no change if value not found, if destination had previous value, 
 *	that memory location is automatically freed
 * IN keyword - string to search for
 * IN/OUT in_line - string to search for keyword, the keyword and value 
 *	(if present) are overwritten by spaces
 * RET 0 if no error, otherwise an error code
 * NOTE: destination must be free when no longer required
 * NOTE: if destination is non-NULL at function call time, it will be freed 
 * NOTE: in_line is overwritten, do not use a constant
 */
extern int load_string (char **destination, char *keyword, char *in_line) ;

#endif