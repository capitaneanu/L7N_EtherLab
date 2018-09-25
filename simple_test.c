#include "ecrt.h"

/* Write to OD entrties using this function */
int ecrt_slave_config_sdo16(
        ec_slave_config_t *sc, /**< Slave configuration */
        uint16_t sdo_index, /**< Index of the SDO to configure. */
        uint8_t sdo_subindex, /**< Subindex of the SDO to configure. */
        uint16_t value /**< Value to set. */
        );


	
	
	
/* Defining PDOs in the program */
	
typedef struct {
    uint16_t alias; /**< Slave alias address. */
    uint16_t position; /**< Slave position. */
    uint32_t vendor_id; /**< Slave vendor ID. */
    uint32_t product_code; /**< Slave product code. */
    uint16_t index; /**< PDO entry index. */
    uint8_t subindex; /**< PDO entry subindex. */
    unsigned int *offset; /**< Pointer to a variable to store the PDO entry's
                       (byte-)offset in the process data. */
    unsigned int *bit_position; /**< Pointer to a variable to store a bit
                                  position (0-7) within the \a offset. Can be
                                  NULL, in which case an error is raised if the
                                  PDO entry does not byte-align. */
} ec_pdo_entry_reg_t;


static uint32_t gkOffOControl;


/* Note that the last one is empty */
const static ec_pdo_entry_reg_t gkDomain1Regs[] = {
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6040, 0, &gkOffOControl},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x607a, 0, &gkOffOPos},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6041, 0, &gkOffIStatus},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6062, 0, &gkOffDPos},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6064, 0, &gkOffIPos},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x606b, 0, &gkOffDVel},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x606c, 0, &gkOffIVel},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6081, 0, &gkOffPVel},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6060, 0, &gkOffOMode},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6061, 0, &gkOffIMode},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x60ff, 0, &gkOffTVel},
    {0, gkDriveNum, 0x00007595, 0x00000000, 0x6077, 0, &gkOffITorq},
    {}
};
	
	/* In the operational mode (motion loop) */
	EC_WRITE_U16(gkDomain1PD + gkOffOControl, 0xF)

	
	
	
	


/* See line 665 of ethercat/include/ecrt.h */
sc = ecrt_master_slave_config(
        ec_master_t *master, /**< EtherCAT master */
        uint16_t alias, /**< Slave alias. */
        uint16_t position, /**< Slave position. */
        uint32_t vendor_id, /**< Expected vendor ID. */
        uint32_t product_code /**< Expected product code. */
        );
/* See line 524 of ethercat/master/slave_config.c */
ecrt_slave_config_sync_manager(sc, 2, EC_DIR_OUTPUT, EC_WD_ENABLE )
ecrt_slave_config_sync_manager(sc, 3, EC_DIR_INPUT, EC_WD_DISABLE )