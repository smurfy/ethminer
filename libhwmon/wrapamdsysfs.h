/*
* Wrapper for AMD SysFS on linux, using adapted code from amdcovc by matszpk
*
* By Philipp Andreas - github@smurfy.de
*/

#pragma once

#if ETH_ETHASHCL
// #define CL_USE_DEPRECATED_OPENCL_1_2_APIS true
// #define CL_HPP_ENABLE_EXCEPTIONS true
// #define CL_HPP_CL_1_2_DEFAULT_BUILD true
// #define CL_HPP_TARGET_OPENCL_VERSION 120
// #define CL_HPP_MINIMUM_OPENCL_VERSION 120
// #include <libethash-cl/CL/cl2.hpp>

// #ifndef CL_DEVICE_TOPOLOGY_AMD
// #define CL_DEVICE_TOPOLOGY_AMD 						0x4037
// #endif

// #ifndef CL_DEVICE_TOPOLOGY_TYPE_PCIE_AMD
// #define CL_DEVICE_TOPOLOGY_TYPE_PCIE_AMD 			1
// #endif
#endif

typedef struct {
	int sysfs_gpucount;
	int *card_sysfs_device_id;  /* map cardidx to filesystem card idx */
	int *sysfs_hwmon_id;        /* filesystem card idx to filesystem hwmon idx */
	int *sysfs_opencl_device_id;          /* map ADL dev to OPENCL dev */
	int *opencl_sysfs_device_id;          /* map OPENCL dev to ADL dev */
} wrap_amdsysfs_handle;

wrap_amdsysfs_handle * wrap_amdsysfs_create();
int wrap_amdsysfs_destroy(wrap_amdsysfs_handle *sysfsh);

int wrap_amdsysfs_get_gpucount(wrap_amdsysfs_handle *sysfsh, int *gpucount);

int wrap_amdsysfs_get_gpu_pci_id(wrap_amdsysfs_handle *sysfsh, int index, char *idbuf, int bufsize);

int wrap_amdsysfs_get_tempC(wrap_amdsysfs_handle *sysfsh, int index, unsigned int *tempC);

int wrap_amdsysfs_get_fanpcnt(wrap_amdsysfs_handle *sysfsh, int index, unsigned int *fanpcnt);

int wrap_amdsysfs_get_power_usage(wrap_amdsysfs_handle *sysfsh, int index, unsigned int *milliwatts);
