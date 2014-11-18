

#include "SPI.h"
#include "boards.h"
#include "app_util_platform.h"
#include "spi_master.h"

#if defined(SPI_MASTER_0_ENABLE)
    #define SPI_MASTER_HW SPI_MASTER_0
#elif defined(SPI_MASTER_1_ENABLE)
    #define SPI_MASTER_HW SPI_MASTER_1
#endif

void SPI_begin()
{
		 spi_master_config_t spi_config = SPI_MASTER_INIT_DEFAULT;
    
    #if defined(SPI_MASTER_0_ENABLE)
        spi_config.SPI_Pin_SCK = SPIM0_SCK_PIN;
        spi_config.SPI_Pin_MISO = SPIM0_MISO_PIN;
        spi_config.SPI_Pin_MOSI = SPIM0_MOSI_PIN;
        spi_config.SPI_Pin_SS = SPIM0_SS_PIN;
    #elif defined(SPI_MASTER_1_ENABLE)
        spi_config.SPI_Pin_SCK = SPIM1_SCK_PIN;
        spi_config.SPI_Pin_MISO = SPIM1_MISO_PIN;
        spi_config.SPI_Pin_MOSI = SPIM1_MOSI_PIN;
        spi_config.SPI_Pin_SS = SPIM1_SS_PIN;
    #endif /* SPI_MASTER_ENABLE */
    
    spi_master_open(SPI_MASTER_HW, &spi_config);
}
