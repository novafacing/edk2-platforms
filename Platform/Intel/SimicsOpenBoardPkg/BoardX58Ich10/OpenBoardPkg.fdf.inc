## @file
#  FDF include file that defines the main macros and sets the dependent PCDs.
#
#  Copyright (C) 2014, Red Hat, Inc.
#  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

#
# Default flash size is 2MB.
#
# Defining FD_SIZE_2MB on the build command line can override this.
#

DEFINE BLOCK_SIZE        = 0x1000
DEFINE VARS_SIZE         = 0x84000
DEFINE VARS_BLOCKS       = 0x84
DEFINE VARS_LIVE_SIZE    = 0x40000
DEFINE VARS_SPARE_SIZE   = 0x42000

DEFINE FW_BASE_ADDRESS   = 0xFF000000
DEFINE FW_SIZE           = 0x01000000
DEFINE FW_BLOCKS         = 0x1000
DEFINE CODE_BASE_ADDRESS = 0xFF084000
DEFINE CODE_SIZE         = 0x00F7C000
DEFINE CODE_BLOCKS       = 0x0F7C
DEFINE FVMAIN_SIZE       = 0x0097C000
DEFINE SECFV_OFFSET      = 0x00A00000
DEFINE SECFV_SIZE        = 0x600000


SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFdBaseAddress     = $(FW_BASE_ADDRESS)
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFirmwareFdSize    = $(FW_SIZE)
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFirmwareBlockSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageVariableBase = $(FW_BASE_ADDRESS)
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize = $(VARS_LIVE_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageVariableBase + gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize
SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwWorkingBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogBase + gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageEventLogSize
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize = $(BLOCK_SIZE)

SET gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwSpareBase = gSimicsOpenBoardPkgTokenSpaceGuid.PcdSimicsFlashNvStorageFtwWorkingBase + gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize
SET gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareSize = $(VARS_SPARE_SIZE)

SET gIntelSiliconPkgTokenSpaceGuid.PcdBiosAreaBaseAddress = $(FW_BASE_ADDRESS)
SET gIntelSiliconPkgTokenSpaceGuid.PcdBiosSize = $(FW_SIZE)

SET gMinPlatformPkgTokenSpaceGuid.PcdFlashAreaBaseAddress = gIntelSiliconPkgTokenSpaceGuid.PcdBiosAreaBaseAddress
SET gMinPlatformPkgTokenSpaceGuid.PcdFlashAreaSize = gIntelSiliconPkgTokenSpaceGuid.PcdBiosSize

DEFINE MEMFD_BASE_ADDRESS = 0x800000
