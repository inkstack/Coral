/*
 The MIT License (MIT)

 Copyright (c) 2015 inkstack.info

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "devices.h"
#include "logger.h"

cl_platform_id
retrieve_platforms (char* platform_vender)
{
  cl_int status;
  cl_device_id device_id = NULL;
  cl_platform_id platform_ids[MAX_PLATFORM_NUMBER];

  cl_uint ret_num_devices = 0;
  cl_uint ret_num_platforms = 0;

  status = clGetPlatformIDs (MAX_PLATFORM_NUMBER, platform_ids, &ret_num_platforms);
  CL_CHECK("Create a platform!", status)
  printf ("There are %d platforms totally.\n", ret_num_platforms);

  int i;
  for (i = 0; i < ret_num_platforms; ++i)
	{
	  cl_platform_id platform_id = platform_ids[i];
	  char platform_name[1024];
	  status = clGetPlatformInfo (platform_id, CL_PLATFORM_NAME, 1024, platform_name, NULL);
	  if (strcmp (platform_vender, platform_name) < 0)
		{
		  status = clGetDeviceIDs (platform_id, CL_DEVICE_TYPE_ALL, MAX_DEVICE_NUMBER, &device_id, &ret_num_devices);
		  CL_CHECK("Error: Failed to create a device group!", status)
		  char device_name[1024];
		  status = clGetDeviceInfo (device_id, CL_DEVICE_NAME, 1024, device_name, NULL);
		  printf ("Get device \"%s\" in platform \"%s\".\n", device_name, platform_name);
		  return device_id;
		}
	}

  return device_id;
}

cl_device_id
retrieve_device (char* platform_vender)
{
  cl_int err;
  cl_device_id device_id = NULL;
  cl_platform_id platform_ids[MAX_PLATFORM_NUMBER];

  cl_uint ret_num_devices = 0;
  cl_uint ret_num_platforms = 0;

  err = clGetPlatformIDs (MAX_PLATFORM_NUMBER, platform_ids, &ret_num_platforms);
  CL_CHECK("Error: Failed to create a platform!", err)
  printf ("There are %d platforms totally.\n", ret_num_platforms);

  int i;
  for (i = 0; i < ret_num_platforms; ++i)
	{
	  cl_platform_id platform_id = platform_ids[i];
	  char platform_name[1024];
	  err = clGetPlatformInfo (platform_id, CL_PLATFORM_NAME, 1024, platform_name, NULL);
	  if (strcmp (platform_vender, platform_name) < 0)
		{
		  err = clGetDeviceIDs (platform_id, CL_DEVICE_TYPE_ALL, MAX_DEVICE_NUMBER, &device_id, &ret_num_devices);
		  CL_CHECK("Error: Failed to create a device group!", err)
		  char device_name[1024];
		  err = clGetDeviceInfo (device_id, CL_DEVICE_NAME, 1024, device_name, NULL);
		  printf ("Get device \"%s\" in platform \"%s\".\n", device_name, platform_name);
		  return device_id;
		}
	}

  return device_id;
}
