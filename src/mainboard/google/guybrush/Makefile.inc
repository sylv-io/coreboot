# SPDX-License-Identifier: GPL-2.0-or-later

bootblock-y += bootblock.c
bootblock-$(CONFIG_CHROMEOS) += chromeos.c

ifneq ($(wildcard $(MAINBOARD_BLOBS_DIR)/APCB_CZN_D4.bin),)
$(info APCB sources present.)
APCB_SOURCES = $(MAINBOARD_BLOBS_DIR)/APCB_CZN_D4.bin
APCB_SOURCES_RECOVERY = $(MAINBOARD_BLOBS_DIR)/APCB_CZN_D4.bin
else
$(info APCB sources not found.  Skipping APCB.)
endif

romstage-y += port_descriptors.c
romstage-y += romstage.c

ramstage-y += mainboard.c
ramstage-y += ec.c
ramstage-$(CONFIG_CHROMEOS) += chromeos.c

verstage-y += verstage.c
verstage-$(CONFIG_CHROMEOS) += chromeos.c

subdirs-y += variants/baseboard
subdirs-y += variants/$(VARIANT_DIR)

CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/variants/baseboard/include
CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/variants/$(VARIANT_DIR)/include

LIB_SPD_DEPS = $(SPD_SOURCES)
