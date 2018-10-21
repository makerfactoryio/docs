# Expansion interfaces

## MikroBUS sockets

!!! info "Pin sharing limitation"
	Please note that, although the STM32F413 MCU provides a rich set and number of peripherals, in some cases the buses need to be shared between the expansion interfaces. 

	For example, the SPI bus is shared between both MikroBUS sockets, which is not a problem if this interface is used as a bus, since two Chip Select lines are exposed (MBx_CS), but if these pins are intended to be used as independent GPIOs, only one interface can be used at a time. Please refer to the [*expansion interfaces*](../interfaces) section for more details.

## Grove connectors

## Arduino R3 socket	