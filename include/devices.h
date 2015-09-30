/**
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 inkstack.info
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/*
 * devices.h
 *
 *  Created on: Sep 30, 2015
 *      Author: Halo9Pan
 */

#ifndef MAX_PLATFORM_NUMBER
#define MAX_PLATFORM_NUMBER 2
#endif

#ifndef MAX_DEVICE_NUMBER
#define MAX_DEVICE_NUMBER 4
#endif

#ifndef INCLUDE_DEVICES_H_
#define INCLUDE_DEVICES_H_

#include <CL/opencl.h>

cl_device_id
retrieve_device (char* platform_vender);

#define CL_CHECK(s, err) if (err != CL_SUCCESS)\
  {\
	printf ("%s %d\n", s, err);\
	return NULL;\
  }\


#endif /* INCLUDE_DEVICES_H_ */
