/*
 * Configuration settings for the Novena U-boot.
 *
 * Copyright (C) 2014 Marek Vasut <marex@denx.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* System configurations */
#define CONFIG_MX6
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_MISC_INIT_R
#define CONFIG_FIT
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DOS_PARTITION
#define CONFIG_FAT_WRITE
#define CONFIG_KEYBOARD
#define CONFIG_MXC_GPIO
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_REGEX
#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_SYS_NO_FLASH

#define CONFIG_NOVENA_LID_FEATURE
#define CONFIG_NOVENA_LID_GPIO		IMX_GPIO_NR(4, 12)

#define CONFIG_DDR_SPD

#include "mx6_common.h"
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <config_defaults.h>

/* U-Boot Commands */
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_BMODE
#define CONFIG_CMD_BOOTZ
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PXE
#define CONFIG_CMD_EEPROM
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_EXT4_WRITE
#define CONFIG_CMD_FAT
#define CONFIG_CMD_FS_GENERIC
#define CONFIG_CMD_I2C
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_FUSE
#define CONFIG_CMD_GPIO
#define CONFIG_CMD_MII
#define CONFIG_CMD_MMC
#define CONFIG_CMD_NET
#define CONFIG_CMD_PING
#define CONFIG_CMD_SATA
#define CONFIG_CMD_SETEXPR
#define CONFIG_CMD_TIME
#define CONFIG_CMD_USB
#define CONFIG_VIDEO
#define CONFIG_MENU

/* U-Boot general configurations */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_CBSIZE	1024		/* Console I/O buffer size */
#define CONFIG_SYS_PBSIZE	\
	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
						/* Print buffer size */
#define CONFIG_SYS_MAXARGS	32		/* Max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE
						/* Boot argument buffer size */
#define CONFIG_VERSION_VARIABLE			/* U-BOOT version */
#define CONFIG_AUTO_COMPLETE			/* Command auto complete */
#define CONFIG_CMDLINE_EDITING			/* Command history etc */
#define CONFIG_SYS_HUSH_PARSER

/* U-Boot environment */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_SIZE			(16 * 1024)
/*
 * Environment is on MMC, starting at offset 512KiB from start of the card.
 * Please place first partition at offset 1MiB from the start of the card
 * as recommended by GNU/fdisk. See below for details:
 * http://homepage.ntlworld.com./jonathan.deboynepollard/FGA/disc-partition-alignment.html
 */
#ifdef CONFIG_CMD_MMC
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_ENV_OFFSET		(512 * 1024)
#define CONFIG_ENV_SIZE_REDUND		CONFIG_ENV_SIZE
#define CONFIG_ENV_OFFSET_REDUND	\
		(CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

/* Booting Linux */
#define CONFIG_BOOTDELAY		0
#define CONFIG_BOOTFILE			"fitImage"
#define CONFIG_BOOTARGS			""
#define CONFIG_BOOTCOMMAND		"run novena_boot"
#define CONFIG_LOADADDR			0x18000000
#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR
#define CONFIG_HOSTNAME			novena

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR
#define PHYS_SDRAM_SIZE			0xF0000000

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_SYS_MEMTEST_START	0x10000000
#define CONFIG_SYS_MEMTEST_END		0x20000000

#define CONFIG_SYS_MALLOC_LEN		(64 * 1024 * 1024)
#define CONFIG_SYS_MALLOC_F_LEN		(1 << 10)

/* SPL */
#define CONFIG_SPL_FAT_SUPPORT
#define CONFIG_SPL_MMC_SUPPORT
#include "imx6_spl.h"			/* common IMX6 SPL configuration */

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Ethernet Configuration */
#ifdef CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		0x7
#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL
#define CONFIG_PHY_MICREL_KSZ9021
#define CONFIG_ARP_TIMEOUT		200UL
#endif

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_I2C_MULTI_BUS
#define CONFIG_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		100000

/* I2C EEPROM */
#ifdef CONFIG_CMD_EEPROM
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	2
#define CONFIG_SYS_SPD_BUS_NUM		2
#endif

/* MMC Configs */
#ifdef CONFIG_CMD_MMC
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CONFIG_SYS_FSL_USDHC_NUM	2
#endif

/* OCOTP Configs */
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

/* PCI express */
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW
#define CONFIG_PCIE_IMX
#define CONFIG_PCIE_IMX_PERST_GPIO	IMX_GPIO_NR(3, 29)
#define CONFIG_PCIE_IMX_RFKILL_GPIO	IMX_GPIO_NR(2, 16)
#define CONFIG_PCIE_IMX_POWER_GPIO	IMX_GPIO_NR(7, 12)
#endif

/* PMIC */
#define CONFIG_POWER
#define CONFIG_POWER_I2C
#define CONFIG_POWER_PFUZE100
#define CONFIG_POWER_PFUZE100_I2C_ADDR	0x08

/* SATA Configs */
#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_DWC_AHSATA_PORT_ID	0
#define CONFIG_DWC_AHSATA_BASE_ADDR	SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

/* UART */
#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE		UART2_BASE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONS_INDEX		1

/* USB Configs */
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_USB_STORAGE
#define CONFIG_USB_KEYBOARD
#define CONFIG_SYS_USB_EVENT_POLL_VIA_CONTROL_EP
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_USB_ETHER_SMSC95XX
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS		0
/* Gadget part */
#define CONFIG_CI_UDC
#define CONFIG_USBD_HS
#define CONFIG_USB_GADGET_DUALSPEED
#define CONFIG_USB_ETHER
#define CONFIG_USB_ETH_CDC
#define CONFIG_NETCONSOLE
#endif

/* Video output */
#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_IPUV3_CLK		260000000
#define CONFIG_CMD_HDMIDETECT
#define CONFIG_CONSOLE_MUX
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP
#endif

#define BOOT_TARGET_DEVICES(func)
#include "config_distro_bootcmd.h"

/* Extra U-Boot environment. */
#define CONFIG_EXTRA_ENV_SETTINGS					\
	BOOTENV								\
	"fdt_high=0xffffffff\0"						\
	"initrd_high=0xffffffff\0"					\
	"baudrate=115200\0"						\
	"bootdev=/dev/mmcblk0p1\0"					\
	"rootdev=/dev/mmcblk0p2\0"					\
	"netdev=eth0\0"							\
	"fdtfile=imx6q-novena.dtb\0"					\
	"kernel_addr_r=0x18000000\0"					\
	"fdt_addr_r=0x11ff0000\0"					\
	"ramdisk_addr_r=0x10ff0000\0"					\
	"scriptaddr=0x10aa0000\0"					\
	"pxe_addr_r=0x10550000\0"					\
	"initrd_addr_r=-\0"						\
	"addcons="							\
		"setenv bootargs ${bootargs} "				\
		"console=${consdev},${baudrate}\0"			\
	"addip="							\
		"setenv bootargs ${bootargs} "				\
		"ip=${ipaddr}:${serverip}:${gatewayip}:"		\
			"${netmask}:${hostname}:${netdev}:off\0"	\
	"addmisc="							\
		"setenv bootargs ${bootargs} ${miscargs}\0"		\
	"addargs=run addcons addmisc\0"					\
	"mmcload="							\
		"mmc rescan ; "						\
		"ext4load mmc 0:1 ${kernel_addr_r} ${bootfile}\0"	\
	"netload="							\
		"tftp ${kernel_addr_r} ${hostname}/${bootfile}\0"	\
	"miscargs=nohlt panic=1\0"					\
	"mmcargs=setenv bootargs root=${rootdev} rw rootwait\0"		\
	"nfsargs="							\
		"setenv bootargs root=/dev/nfs rw "			\
			"nfsroot=${serverip}:${rootpath},v3,tcp\0"	\
	"mmc_mmc="							\
		"run mmcload mmcargs addargs ; "			\
		"bootm ${kernel_addr_r}\0"				\
	"mmc_nfs="							\
		"run mmcload nfsargs addip addargs ; "			\
		"bootm ${kernel_addr_r}\0"				\
	"net_mmc="							\
		"run netload mmcargs addargs ; "			\
		"bootm ${kernel_addr_r}\0"				\
	"net_nfs="							\
		"run netload nfsargs addip addargs ; "			\
		"bootm ${kernel_addr_r}\0"				\
	"stdin=serial,usbkbd\0"						\
	"stdout=serial,vga\0"						\
	"stderr=serial,vga\0"						\
	"bootargs=init=/lib/systemd/systemd rootwait rw\0"		\
	"bootenv=uEnv.txt\0"						\
        "loadbootenv=load ${bootsrc} ${bootdev} ${loadaddr} ${bootenv}\0" \
	"importbootenv="						\
		"echo Importing environment from ${bootsrc} ... ; "	\
		"env import -t -r $loadaddr $filesize\0"		\
	"rootdev=PARTUUID=4e6f764d-03\0" /* NovM */			\
	"bootpart=1\0"							\
	"loaduenv="							\
		"if run loadbootenv; then "				\
			"echo Loaded environment from ${bootenv} ; "	\
			"run importbootenv ; "				\
		"else ; "						\
			"echo To override boot, create a file on the "	\
				"internal MMC called ${bootenv} ; "	\
		"fi\0"							\
	"doearlyhook="							\
		"if test -n $earlyhook; then "				\
			"echo Running earlyhook ... ; "			\
			"run earlyhook ; "				\
		"else ; "						\
			"echo To hook early boot process, add a "	\
				"variable called earlyhook ; "		\
		"fi\0"							\
	"dolatehook="							\
		"if test -n ${finalhook} ; then "			\
			"echo Running finalhook ... ; "			\
			"run importbootenv ; "				\
			"run finalhook ; "				\
		"else ; "						\
			"echo To hook late boot process, add "		\
				"a variable called finalhook ; "	\
		"fi\0"							\
	"novena_boot="							\
		"run loaduenv ; "					\
		"run doearlyhook ; "					\
		"if lcddet ; then "					\
			"echo IT6251 bridge chip detected ; "		\
			"setenv keep_lcd true ; "			\
			"setenv video true ; "				\
		"elif hdmidet ; then "					\
			"echo HDMI monitor detected ; "			\
			"setenv video true ; "				\
		"else ; "						\
			"echo No video detected, using serial port ; "	\
			"setenv video false ; "				\
		"fi ; "							\
		"if gpio input 110 ; then " /* Test recovery button */  \
			"echo Press Control-C to enter U-Boot shell, "	\
				"or wait to enter recovery mode ; "	\
			"if sleep 2 ; then true; else exit ; fi ; "	\
			"echo Entering recovery mode... ; "		\
			"setenv rec .recovery ;	"			\
			"setenv bootargs ${bootargs} recovery ; "	\
		"else ; "						\
			"echo Hold recovery button to boot to "		\
			"recovery, or to enter U-Boot shell. ; "	\
		"fi ; "							\
		"if run video ; then "					\
			"setenv console-bootarg tty0 ; "			\
		"else ; "						\
			"setenv console-bootarg ttymxc1,${baudrate} ; "	\
		"fi ; "							\
		"if test -n \"${sata_root}\" && test -z \"${rec}\"; then "	\
			"sata init ; "					\
			"setenv devtype sata ; "			\
			"setenv devnum 0 ; "				\
			"setenv rootdev PARTUUID=4e6f7653-03 ; " /* NovS */ \
		"else ; "						\
			"setenv devtype ${bootsrc} ; "			\
			"setenv devnum ${bootdev} ; "			\
		"fi ; "							\
		"setenv bootargs ${bootargs} root=${rootdev} ; "	\
		"setenv boot_extlinux \"usb start; ${boot_extlinux}\" ;"\
		"run dolatehook ; "					\
		"run scan_dev_for_boot ; " 				\
		"fatload ${bootsrc} ${bootdev} "			\
			"${kernel_addr_r} zImage${rec} ; "		\
		"fatload ${bootsrc} ${bootdev} "			\
			"${fdt_addr_r} novena${rec}.dtb ; "		\
		"fdt addr ${fdt_addr_r}	; "				\
		"bootz ${kernel_addr_r} "				\
			"${initrd_addr_r} "				\
			"${fdt_addr_r} ; "				\
		"\0"							\
	"update_sd_spl_filename=SPL\0"					\
	"update_sd_uboot_filename=u-boot.img\0"				\
	"update_sd_firmware="	/* Update the SD firmware partition */	\
		"if mmc rescan ; then "					\
		"if dhcp ${update_sd_spl_filename} ; then "		\
		"mmc write ${loadaddr} 2 0x200 ; "			\
		"fi ; "							\
		"if dhcp ${update_sd_uboot_filename} ; then "		\
		"fatwrite mmc 0:1 ${loadaddr} u-boot.img ${filesize} ; "\
		"fi ; "							\
		"fi\0"							\

#endif				/* __CONFIG_H */
