# PLATFORM HAL Documentation

## Acronyms

- `HAL` \- Hardware Abstraction Layer
- `RDK-B` \- Reference Design Kit for Broadband Devices
- `OEM` \- Original Equipment Manufacture

## Description

The diagram below describes a high-level software architecture of the Platform HAL module stack.

![Platform HAL Architecture Diag](images/Platform_HAL_Architecture.png)

Platform HAL is an abstraction layer, implemented to interact with vendor software's for getting the hardware specific details such as Firmware Name, Boot loader Version, etc.

## Component Runtime Execution Requirements

### Initialization and Startup

Below Initialization API's provide opportunity for the HAL code to initialize the appropriate DB's,start threads etc.

The client is expected to call the corresponding API (in any order), during the boot sequence.

- `platform_hal_PandMDBInit()`
- `platform_hal_DocsisParamsDBInit()`
- `platform_hal_initThermal()`

3rd party vendors will implement appropriately to meet operational requirements. This interface is expected to block if the hardware is not ready.

## Threading Model

The interface is not thread safe.

Any module which is invoking the API should ensure calls are made in a thread safe manner.

Different 3rd party vendors allowed to create internal threads to meet the operational requirements. In this case 3rd party implementations
should be responsible to synchronize between the calls, events and cleanup the thread.

## Process Model

All API's are expected to be called from multiple process.

## Memory Model

The client is responsible to allocate and de-allocate memory for necessary API's as specified in API Documentation.

Different 3rd party vendors allowed to allocate memory for internal operational requirements. In this case 3rd party implementations
should be responsible to de-allocate internally.

## Power Management Requirements

The HAL is not involved in any of the power management operation.
Any power management state transitions MUST not affect the operation of the HAL.

## Asynchronous Notification Model

There are no asynchronous notifications.

## Blocking calls

The API's are expected to work synchronously and should complete within a time period commensurate with the complexity of the operation and in accordance with any relevant specification.

Any calls that can fail due to the lack of a response should have a timeout period in accordance with any API documentation.

## Internal Error Handling

All the Platform HAL API's should return error synchronously as a return argument. HAL is responsible to handle system errors(e.g. out of memory) internally.

## Persistence Model

There is no requirement for HAL to persist any setting information. The caller is responsible to persist any settings related to their implementation.

## Nonfunctional requirements

Following non functional requirement should be supported by the component.

## Logging and debugging requirements

The component is should log all the error and critical informative messages which helps to debug/triage the issues and understand the functional flow of the system.

The logging should be consistence across all HAL components.

If the vendor is going to log then it has to be logged in `xxx_vendor_hal.log` file name.

Logging should be defined with log levels as per Linux standard logging.

## Memory and performance requirements

The component should not contributing more to memory and CPU utilization while performing normal operations and commensurate with the operation required.

## Quality Control

Platform HAL implementation should pass `Coverity`, `Black duck`, `Valgrind` checks without any issue.

There should not be any memory leaks/corruption introduced by HAL and underneath 3rd party software implementation.

## Licensing

Platform HAL implementation is expected to released under the Apache License 2.0.

## Build Requirements

The source code should be build under Linux Yocto environment and should be delivered as a shared library named as `libhal_platform.so`
  
## Variability Management

Any new API introduced should be implemented by all the 3rd party module and RDK generic code should be compatible with specific version of HAL software.

Each API interface will be versioned using [Semantic Versioning 2.0.0](https://semver.org/), the vendor code will comply with a specific version of the interface.

## Platform or Product Customization

The product can be configured via the following compile time defines:

```c
FEATURE_RDKB_LED_MANAGER        # Enable the LED Manager
FEATURE_RDKB_THERMAL_MANAGER    # Enable the Thermal Manager
```

## Interface API Documentation

All HAL function prototypes and datatype definitions are available in `platform_hal.h` file.

1. Components/Process must include `platform_hal.h` to make use of platform hal capabilities.
2. Components/Process should add linker dependency for `libhal_platform.so`

## Theory of operation and key concepts

Covered as per "Description" sections in the API documentation.

## Sequence Diagram

```mermaid
sequenceDiagram
participant Caller
participant Platform HAL
participant Vendor
Note over Caller: Init once during bootup, Needed for Dependent API's. <br> Ignore this if caller doesn't have any Dependent API's
Caller->>Platform HAL: platform_hal_XXXInit()
Platform HAL->>Vendor: 
Vendor ->>Platform HAL: 
Platform HAL->>Caller: platform_hal_XXXInit() return

Caller->>Platform HAL: platform_hal_GetXXX()
Platform HAL->>Vendor: 
Vendor ->>Platform HAL: 
Platform HAL->>Caller: platform_hal_GetXXX() return

Caller->>Platform HAL: platform_hal_SetXXX()
Platform HAL->>Vendor: 
Vendor ->>Platform HAL: 
Platform HAL->>Caller: platform_hal_SetXXX() return
```
