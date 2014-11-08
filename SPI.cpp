

#include "SPI.h"
#include "boards.h"
#include "app_util_platform.h"
#include "spi_master.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifdef __cplusplus
} // extern "C"
#endif

//typedef struct
//{
//    NRF_SPI_Type * p_nrf_spi;   /**< A pointer to the NRF SPI master */
//    IRQn_Type irq_type;         /**< A type of NVIC IRQn */

//    uint8_t * p_tx_buffer;      /**< A pointer to TX buffer. */
//    uint16_t tx_length;         /**< A length of TX buffer. */
//    uint16_t tx_index;          /**< A index of the current element in the TX buffer. */

//    uint8_t * p_rx_buffer;      /**< A pointer to RX buffer. */
//    uint16_t rx_length;         /**< A length RX buffer. */
//    uint16_t rx_index;          /**< A index of the current element in the RX buffer. */

//    uint16_t max_length;        /**< Max length (Max of the TX and RX length). */
//    uint16_t bytes_count;
//    uint8_t pin_slave_select;   /**< A pin for Slave Select. */

//    spi_master_event_handler_t callback_event_handler;  /**< A handler for event callback function. */

//    spi_master_state_t state;   /**< A state of an instance of SPI master. */
//    bool started_flag;
//    bool disable_all_irq;

//} spi_master_instance_t;


//#if defined(SPI_MASTER_0_ENABLE)
//    #define SPI_MASTER_HW SPI_MASTER_0
//#elif defined(SPI_MASTER_1_ENABLE)
//    #define SPI_MASTER_HW SPI_MASTER_1
//#endif

//#define _static static

//_static volatile spi_master_instance_t m_spi_master_instances[SPI_MASTER_HW_ENABLED_COUNT];

//static __INLINE volatile spi_master_instance_t * spi_master_get_instance(
//    const spi_master_hw_instance_t spi_master_hw_instance);

//static __INLINE volatile spi_master_instance_t * spi_master_get_instance(
//    const spi_master_hw_instance_t spi_master_hw_instance)
//{
//    if (spi_master_hw_instance < SPI_MASTER_HW_ENABLED_COUNT)
//    {
//        return &(m_spi_master_instances[(uint8_t)spi_master_hw_instance]);
//    }
//    return NULL;
//}

//uint32_t spi_master_open(const spi_master_hw_instance_t    spi_master_hw_instance,
//                         spi_master_config_t const * const p_spi_master_config)
//{
//		  /* Check against null */
//    if (p_spi_master_config == NULL)
//    {
//        return NRF_ERROR_NULL;
//    }

//    volatile spi_master_instance_t * p_spi_instance = spi_master_get_instance(
//        spi_master_hw_instance);

//    return NRF_SUCCESS;
//}

void SPIClass::begin()
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
    
    //spi_master_open(SPI_MASTER_HW, &spi_config);
}
