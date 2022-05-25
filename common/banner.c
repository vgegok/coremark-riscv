/*
 * Copyright (c) 2018, Marcelo Samsoniuk
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#define RLE 1

#include <stdio.h>

void banner(void)
{
#ifndef RLE

  // https://github.com/riscv/riscv-pk/blob/master/bbl/riscv_logo.txt
  // https://github.com/riscv/riscv-pk/blob/master/LICENSE.riscv_logo.txt
  // Copyright (C) 2015 Andrew Waterman

  char *logo =
    "    ____             __   ____  _________ _______    __\n"
    "   / __ \\____ ______/ /__/ __ \\/  _/ ___// ____/ |  / /\n"
    "  / / / / __ `/ ___/ //_/ /_/ // / \\__ \\/ /    | | / / \n"
    " / /_/ / /_/ / /  / ,< / _, _// / ___/ / /___  | |/ /  \n"
    "/_____/\\__,_/_/  /_/|_/_/ |_/___//____/\\____/  |___/   \n"
    "\n"
    "        https://github.com/darklife/darkriscv\n\n";

  // rle compressor: 1030 to 269 bytes! +_+

  register int xc=0,xs=0,xp;

  printf("  char rle_logo[] = {\n");

  for(xp=0;;xp++)
  {
      if(xc!=logo[xp])
      {
          if(xc)
          {
              printf("0x%x, 0x%x, ",xc,xs);
          }
          xs=1;
          if(!(xc=logo[xp])) break;
      }
      else xs++;
  }

  printf("0x00 };\n");

#else
  
  char rle_logo[] = {
    0x20, 0x04, 0x5f, 0x04, 0x20, 0x0d, 0x5f, 0x02, 0x20, 0x03, 0x5f, 0x04, 
    0x20, 0x02, 0x5f, 0x09, 0x20, 0x01, 0x5f, 0x07, 0x20, 0x04, 0x5f, 0x02, 
    0x0a, 0x01, 0x20, 0x03, 0x2f, 0x01, 0x20, 0x01, 0x5f, 0x02, 0x20, 0x01, 
    0x5c, 0x01, 0x5f, 0x04, 0x20, 0x01, 0x5f, 0x06, 0x2f, 0x01, 0x20, 0x01, 
    0x2f, 0x01, 0x5f, 0x02, 0x2f, 0x01, 0x20, 0x01, 0x5f, 0x02, 0x20, 0x01, 
    0x5c, 0x01, 0x2f, 0x01, 0x20, 0x02, 0x5f, 0x01, 0x2f, 0x01, 0x20, 0x01, 
    0x5f, 0x03, 0x2f, 0x02, 0x20, 0x01, 0x5f, 0x04, 0x2f, 0x01, 0x20, 0x01, 
    0x7c, 0x01, 0x20, 0x02, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 0x0a, 0x01, 
    0x20, 0x02, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x5f, 0x02, 0x20, 0x01, 0x60, 0x01, 
    0x2f, 0x01, 0x20, 0x01, 0x5f, 0x03, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x02, 
    0x5f, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 0x5f, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x02, 0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x5c, 0x01, 
    0x5f, 0x02, 0x20, 0x01, 0x5c, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x04, 0x7c, 0x01, 0x20, 0x01, 0x7c, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x0a, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x5f, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x5f, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x20, 0x02, 0x2f, 0x01, 0x20, 0x01, 0x2c, 0x01, 
    0x3c, 0x01, 0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x5f, 0x01, 0x2c, 0x01, 
    0x20, 0x01, 0x5f, 0x01, 0x2f, 0x02, 0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 
    0x5f, 0x03, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 0x20, 0x01, 0x2f, 0x01, 
    0x5f, 0x03, 0x20, 0x02, 0x7c, 0x01, 0x20, 0x01, 0x7c, 0x01, 0x2f, 0x01, 
    0x20, 0x01, 0x2f, 0x01, 0x20, 0x02, 0x0a, 0x01, 0x2f, 0x01, 0x5f, 0x05, 
    0x2f, 0x01, 0x5c, 0x01, 0x5f, 0x02, 0x2c, 0x01, 0x5f, 0x01, 0x2f, 0x01, 
    0x5f, 0x01, 0x2f, 0x01, 0x20, 0x02, 0x2f, 0x01, 0x5f, 0x01, 0x2f, 0x01, 
    0x7c, 0x01, 0x5f, 0x01, 0x2f, 0x01, 0x5f, 0x01, 0x2f, 0x01, 0x20, 0x01, 
    0x7c, 0x01, 0x5f, 0x01, 0x2f, 0x01, 0x5f, 0x03, 0x2f, 0x02, 0x5f, 0x04, 
    0x2f, 0x01, 0x5c, 0x01, 0x5f, 0x04, 0x2f, 0x01, 0x20, 0x02, 0x7c, 0x01, 
    0x5f, 0x03, 0x2f, 0x01, 0x20, 0x03, 0x0a, 0x02, 0x20, 0x08, 0x68, 0x01, 
    0x74, 0x02, 0x70, 0x01, 0x73, 0x01, 0x3a, 0x01, 0x2f, 0x02, 0x67, 0x01, 
    0x69, 0x01, 0x74, 0x01, 0x68, 0x01, 0x75, 0x01, 0x62, 0x01, 0x2e, 0x01, 
    0x63, 0x01, 0x6f, 0x01, 0x6d, 0x01, 0x2f, 0x01, 0x64, 0x01, 0x61, 0x01, 
    0x72, 0x01, 0x6b, 0x01, 0x6c, 0x01, 0x69, 0x01, 0x66, 0x01, 0x65, 0x01, 
    0x2f, 0x01, 0x64, 0x01, 0x61, 0x01, 0x72, 0x01, 0x6b, 0x01, 0x72, 0x01, 
    0x69, 0x01, 0x73, 0x01, 0x63, 0x01, 0x76, 0x01, 0x0a, 0x02, 0x00 };

  //printf("\33[H\33[2J");
  putchar('\n');
  
  register int c,s;
  register char *p = rle_logo;
  
  while(*p)
  {
      c = *p++;
      s = *p++;
      
      while(s--) putchar(c);
  }

#endif
}
