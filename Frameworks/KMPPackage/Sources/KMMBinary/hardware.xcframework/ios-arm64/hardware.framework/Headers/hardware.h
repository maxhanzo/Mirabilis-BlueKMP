#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class CBCharacteristic, CBDescriptor, CBService, HardwareBleCharacteristics, HardwareBleConfig, HardwareBleDevice, HardwareBleDeviceState, HardwareBleErrorConnectionClosed, HardwareBleErrorUnknown, HardwareBleFilter, HardwareBleFilterNamePrefix, HardwareBleScanState, HardwareBleService<DEVICE>, HardwareBleServices, HardwareBleWriteType, HardwareClientProvider, HardwareCoreDiscoveredCharacteristic, HardwareCoreDiscoveredDescriptor, HardwareCoreDiscoveredService, HardwareCoreFilter, HardwareCoreFilterNamePrefix, HardwareCoreWriteType, HardwareExceptionsIOException, HardwareExceptionsNotConnectedException, HardwareFileTransferProtocol, HardwareFileTransferProtocolChunk, HardwareFileTransferStateCancelled, HardwareFileTransferStateCompleted, HardwareFileTransferStateDownloading, HardwareFileTransferStateFailed, HardwareFileTransferStateIdle, HardwareFileTransferStateUploading, HardwareKableClient, HardwareKotlinAbstractCoroutineContextElement, HardwareKotlinAbstractCoroutineContextKey<B, E>, HardwareKotlinArray<T>, HardwareKotlinByteArray, HardwareKotlinByteIterator, HardwareKotlinCancellationException, HardwareKotlinEnum<E>, HardwareKotlinEnumCompanion, HardwareKotlinException, HardwareKotlinIllegalStateException, HardwareKotlinPair<__covariant A, __covariant B>, HardwareKotlinRuntimeException, HardwareKotlinThrowable, HardwareKotlinUnit, HardwareKotlinx_coroutines_coreCoroutineDispatcher, HardwareKotlinx_coroutines_coreCoroutineDispatcherKey, HardwareLogProvider, HardwareMirabilisBlueCharacteristics, HardwareMirabilisBlueConfig, HardwareMirabilisBlueDevice, HardwareMirabilisBlueError, HardwareMirabilisBlueErrorEmptyFile, HardwareMirabilisBlueErrorFileTooLarge, HardwareMirabilisBlueErrorMalformedPacket, HardwareMirabilisBlueErrorNegativeAcknowledgement, HardwareMirabilisBlueErrorTransferCancelled, HardwareMirabilisBlueErrorTransferInProgress, HardwareMirabilisBlueServices, HardwareProvideScope, HardwareUuidUuid, NSData, NSError;

@protocol HardwareBleClient, HardwareBleError, HardwareBleScan, HardwareCoreCharacteristic, HardwareCoreDescriptor, HardwareCorePeripheral, HardwareCoreService, HardwareFileTransferState, HardwareKotlinComparable, HardwareKotlinContinuation, HardwareKotlinContinuationInterceptor, HardwareKotlinCoroutineContext, HardwareKotlinCoroutineContextElement, HardwareKotlinCoroutineContextKey, HardwareKotlinFunction, HardwareKotlinIterator, HardwareKotlinSequence, HardwareKotlinSuspendFunction0, HardwareKotlinx_coroutines_coreCancellableContinuation, HardwareKotlinx_coroutines_coreChildHandle, HardwareKotlinx_coroutines_coreChildJob, HardwareKotlinx_coroutines_coreDisposableHandle, HardwareKotlinx_coroutines_coreFlow, HardwareKotlinx_coroutines_coreFlowCollector, HardwareKotlinx_coroutines_coreJob, HardwareKotlinx_coroutines_coreMutableSharedFlow, HardwareKotlinx_coroutines_coreMutableStateFlow, HardwareKotlinx_coroutines_coreParentJob, HardwareKotlinx_coroutines_coreRunnable, HardwareKotlinx_coroutines_coreSelectClause, HardwareKotlinx_coroutines_coreSelectClause0, HardwareKotlinx_coroutines_coreSelectInstance, HardwareKotlinx_coroutines_coreSharedFlow, HardwareKotlinx_coroutines_coreStateFlow;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface HardwareBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface HardwareBase (HardwareBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface HardwareMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface HardwareMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorHardwareKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface HardwareNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface HardwareByte : HardwareNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface HardwareUByte : HardwareNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface HardwareShort : HardwareNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface HardwareUShort : HardwareNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface HardwareInt : HardwareNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface HardwareUInt : HardwareNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface HardwareLong : HardwareNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface HardwareULong : HardwareNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface HardwareFloat : HardwareNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface HardwareDouble : HardwareNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface HardwareBoolean : HardwareNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("BleDevice")))
@interface HardwareBleDevice : HardwareBase
- (instancetype)initWithClient:(id<HardwareBleClient>)client liveInfo:(BOOL)liveInfo __attribute__((swift_name("init(client:liveInfo:)"))) __attribute__((objc_designated_initializer));
- (HardwareBleDeviceState *)getCurrentState __attribute__((swift_name("getCurrentState()")));
- (NSString *)getIdentifier __attribute__((swift_name("getIdentifier()")));
- (NSString *)getName __attribute__((swift_name("getName()")));
@end

__attribute__((swift_name("BleService")))
@interface HardwareBleService<DEVICE> : HardwareBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DEVICE _Nullable)clientToClient:(id<HardwareBleClient> _Nullable)client __attribute__((swift_name("clientTo(client:)")));
- (void)flush __attribute__((swift_name("flush()")));
- (id<HardwareBleScan>)getScan __attribute__((swift_name("getScan()")));
- (void)startScanTimeout:(int64_t)timeout __attribute__((swift_name("startScan(timeout:)")));
- (void)stopScan __attribute__((swift_name("stopScan()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleCharacteristics")))
@interface HardwareBleCharacteristics : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bleCharacteristics __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareBleCharacteristics *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *BATTERY_LEVEL __attribute__((swift_name("BATTERY_LEVEL")));
@property (readonly) NSString *FIRMWARE_REVISION __attribute__((swift_name("FIRMWARE_REVISION")));
@property (readonly) NSString *HARDWARE_REVISION __attribute__((swift_name("HARDWARE_REVISION")));
@property (readonly) NSString *LOCATION __attribute__((swift_name("LOCATION")));
@property (readonly) NSString *MANUFACTURER_NAME __attribute__((swift_name("MANUFACTURER_NAME")));
@property (readonly) NSString *MODEL_NUMBER __attribute__((swift_name("MODEL_NUMBER")));
@property (readonly) NSString *SERIAL_NUMBER __attribute__((swift_name("SERIAL_NUMBER")));
@property (readonly) NSString *SOFTWARE_REVISION __attribute__((swift_name("SOFTWARE_REVISION")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleConfig")))
@interface HardwareBleConfig : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bleConfig __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareBleConfig *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t operationTimeout __attribute__((swift_name("operationTimeout")));
@property (readonly) int64_t scanTimeout __attribute__((swift_name("scanTimeout")));
@end

__attribute__((swift_name("BleFilter")))
@interface HardwareBleFilter : HardwareBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleFilter.NamePrefix")))
@interface HardwareBleFilterNamePrefix : HardwareBleFilter
- (instancetype)initWithPrefix:(NSString *)prefix __attribute__((swift_name("init(prefix:)"))) __attribute__((objc_designated_initializer));
- (HardwareBleFilterNamePrefix *)doCopyPrefix:(NSString *)prefix __attribute__((swift_name("doCopy(prefix:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *prefix __attribute__((swift_name("prefix")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleServices")))
@interface HardwareBleServices : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bleServices __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareBleServices *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *DEVICE_INFORMATION __attribute__((swift_name("DEVICE_INFORMATION")));
@property (readonly) NSString *DFU __attribute__((swift_name("DFU")));
@end

__attribute__((swift_name("BleError")))
@protocol HardwareBleError
@required
@end

__attribute__((swift_name("KotlinThrowable")))
@interface HardwareKotlinThrowable : HardwareBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (HardwareKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) HardwareKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorCharacteristicNotFound")))
@interface HardwareBleErrorCharacteristicNotFound : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic throwable:(HardwareKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorConnection")))
@interface HardwareBleErrorConnection : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithIdentifier:(HardwareUuidUuid *)identifier throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(identifier:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorConnectionClosed")))
@interface HardwareBleErrorConnectionClosed : HardwareKotlinThrowable <HardwareBleError>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)connectionClosed __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareBleErrorConnectionClosed *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorDisconnection")))
@interface HardwareBleErrorDisconnection : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithIdentifier:(HardwareUuidUuid *)identifier throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(identifier:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorObserveCharacteristic")))
@interface HardwareBleErrorObserveCharacteristic : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorOperationFailed")))
@interface HardwareBleErrorOperationFailed : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadBattery")))
@interface HardwareBleErrorReadBattery : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadCharacteristic")))
@interface HardwareBleErrorReadCharacteristic : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadFirmware")))
@interface HardwareBleErrorReadFirmware : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadHardware")))
@interface HardwareBleErrorReadHardware : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadManufacture")))
@interface HardwareBleErrorReadManufacture : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadModelNumber")))
@interface HardwareBleErrorReadModelNumber : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadOperation")))
@interface HardwareBleErrorReadOperation : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString *)characteristic throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadSerial")))
@interface HardwareBleErrorReadSerial : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorReadSoftware")))
@interface HardwareBleErrorReadSoftware : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorSafeReadCharacteristic")))
@interface HardwareBleErrorSafeReadCharacteristic : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorSafeWriteCharacteristic")))
@interface HardwareBleErrorSafeWriteCharacteristic : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic throwable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(characteristic:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorServiceNotFound")))
@interface HardwareBleErrorServiceNotFound : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithService:(NSString * _Nullable)service __attribute__((swift_name("init(service:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorUnknown")))
@interface HardwareBleErrorUnknown : HardwareKotlinThrowable <HardwareBleError>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)unknown __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareBleErrorUnknown *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorUnknownConnection")))
@interface HardwareBleErrorUnknownConnection : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithThrowable:(HardwareKotlinThrowable *)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleErrorWriteCharacteristic")))
@interface HardwareBleErrorWriteCharacteristic : HardwareKotlinThrowable <HardwareBleError>
- (instancetype)initWithCharacteristic:(NSString * _Nullable)characteristic byteArray:(HardwareKotlinByteArray *)byteArray throwable:(HardwareKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(characteristic:byteArray:throwable:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol HardwareKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface HardwareKotlinEnum<E> : HardwareBase <HardwareKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) HardwareKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleDeviceState")))
@interface HardwareBleDeviceState : HardwareKotlinEnum<HardwareBleDeviceState *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) HardwareBleDeviceState *disconnected __attribute__((swift_name("disconnected")));
@property (class, readonly) HardwareBleDeviceState *disconnecting __attribute__((swift_name("disconnecting")));
@property (class, readonly) HardwareBleDeviceState *connected __attribute__((swift_name("connected")));
@property (class, readonly) HardwareBleDeviceState *connecting __attribute__((swift_name("connecting")));
@property (class, readonly) HardwareBleDeviceState *unknown __attribute__((swift_name("unknown")));
+ (HardwareKotlinArray<HardwareBleDeviceState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<HardwareBleDeviceState *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleScanState")))
@interface HardwareBleScanState : HardwareKotlinEnum<HardwareBleScanState *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) HardwareBleScanState *idle __attribute__((swift_name("idle")));
@property (class, readonly) HardwareBleScanState *scanningOn __attribute__((swift_name("scanningOn")));
@property (class, readonly) HardwareBleScanState *deviceFound __attribute__((swift_name("deviceFound")));
@property (class, readonly) HardwareBleScanState *error __attribute__((swift_name("error")));
@property (class, readonly) HardwareBleScanState *scanningOff __attribute__((swift_name("scanningOff")));
+ (HardwareKotlinArray<HardwareBleScanState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<HardwareBleScanState *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleWriteType")))
@interface HardwareBleWriteType : HardwareKotlinEnum<HardwareBleWriteType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) HardwareBleWriteType *withresponse __attribute__((swift_name("withresponse")));
@property (class, readonly) HardwareBleWriteType *withoutresponse __attribute__((swift_name("withoutresponse")));
+ (HardwareKotlinArray<HardwareBleWriteType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<HardwareBleWriteType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("BleClient")))
@protocol HardwareBleClient
@required
- (HardwareKotlinByteArray * _Nullable)getAdvertisementData __attribute__((swift_name("getAdvertisementData()")));
- (NSString *)getIdentifier __attribute__((swift_name("getIdentifier()")));
- (NSString *)getName __attribute__((swift_name("getName()")));
@property HardwareBleDeviceState *currentState __attribute__((swift_name("currentState")));
@end

__attribute__((swift_name("BleScan")))
@protocol HardwareBleScan
@required
- (void)flush __attribute__((swift_name("flush()")));
- (void)startScanTimeout:(int64_t)timeout __attribute__((swift_name("startScan(timeout:)")));
- (void)stopScan __attribute__((swift_name("stopScan()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientProvider")))
@interface HardwareClientProvider : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)clientProvider __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareClientProvider *shared __attribute__((swift_name("shared")));
- (id<HardwareBleClient>)clientFromValue:(HardwareKotlinPair<id<HardwareCorePeripheral>, HardwareKotlinByteArray *> *)value __attribute__((swift_name("clientFrom(value:)")));
- (id<HardwareBleClient>)mockClientFromName:(NSString *)name identifier:(NSString *)identifier __attribute__((swift_name("mockClientFrom(name:identifier:)")));
- (id<HardwareBleScan>)mockScanWith __attribute__((swift_name("mockScanWith()")));
- (id<HardwareBleScan>)scanWithFilters:(NSArray<HardwareBleFilter *> *)filters advertisementDataService:(NSString * _Nullable)advertisementDataService __attribute__((swift_name("scanWith(filters:advertisementDataService:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableClient")))
@interface HardwareKableClient : HardwareBase <HardwareBleClient>
- (instancetype)initWithPeripheral:(id<HardwareCorePeripheral>)peripheral advertisementData:(HardwareKotlinByteArray * _Nullable)advertisementData __attribute__((swift_name("init(peripheral:advertisementData:)"))) __attribute__((objc_designated_initializer));
- (HardwareKotlinByteArray * _Nullable)getAdvertisementData __attribute__((swift_name("getAdvertisementData()")));
- (NSString *)getIdentifier __attribute__((swift_name("getIdentifier()")));
- (NSString *)getName __attribute__((swift_name("getName()")));
@property HardwareBleDeviceState *currentState __attribute__((swift_name("currentState")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableScan")))
@interface HardwareKableScan : HardwareBase <HardwareBleScan>
- (instancetype)initWithFilters:(NSArray<HardwareBleFilter *> *)filters advertisementDataService:(NSString * _Nullable)advertisementDataService __attribute__((swift_name("init(filters:advertisementDataService:)"))) __attribute__((objc_designated_initializer));
- (void)flush __attribute__((swift_name("flush()")));
- (void)startScanTimeout:(int64_t)timeout __attribute__((swift_name("startScan(timeout:)")));
- (void)stopScan __attribute__((swift_name("stopScan()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MockClient")))
@interface HardwareMockClient : HardwareBase <HardwareBleClient>
- (instancetype)initWithName:(NSString *)name identifier:(NSString *)identifier __attribute__((swift_name("init(name:identifier:)"))) __attribute__((objc_designated_initializer));
- (HardwareKotlinByteArray * _Nullable)getAdvertisementData __attribute__((swift_name("getAdvertisementData()")));
- (NSString *)getIdentifier __attribute__((swift_name("getIdentifier()")));
- (NSString *)getName __attribute__((swift_name("getName()")));
@property HardwareBleDeviceState *currentState __attribute__((swift_name("currentState")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MockScan")))
@interface HardwareMockScan : HardwareBase <HardwareBleScan>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)flush __attribute__((swift_name("flush()")));
- (void)startScanTimeout:(int64_t)timeout __attribute__((swift_name("startScan(timeout:)")));
- (void)stopScan __attribute__((swift_name("stopScan()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueCharacteristics")))
@interface HardwareMirabilisBlueCharacteristics : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mirabilisBlueCharacteristics __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueCharacteristics *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *BASIC_WRITE __attribute__((swift_name("BASIC_WRITE")));
@property (readonly) NSString *FILE_TRANSFER_RX __attribute__((swift_name("FILE_TRANSFER_RX")));
@property (readonly) NSString *FILE_TRANSFER_TX __attribute__((swift_name("FILE_TRANSFER_TX")));
@property (readonly) NSString *FIRMWARE_REVISION __attribute__((swift_name("FIRMWARE_REVISION")));
@property (readonly) NSString *HARDWARE_REVISION __attribute__((swift_name("HARDWARE_REVISION")));
@property (readonly) NSString *LAST_WRITE_WITHOUT_RESPONSE_VALUE __attribute__((swift_name("LAST_WRITE_WITHOUT_RESPONSE_VALUE")));
@property (readonly) NSString *LAST_WRITTEN_VALUE __attribute__((swift_name("LAST_WRITTEN_VALUE")));
@property (readonly) NSString *OBSERVABLE_VALUE __attribute__((swift_name("OBSERVABLE_VALUE")));
@property (readonly) NSString *OBSERVABLE_WRITE __attribute__((swift_name("OBSERVABLE_WRITE")));
@property (readonly) NSString *PERIODIC_EVENT_STREAM __attribute__((swift_name("PERIODIC_EVENT_STREAM")));
@property (readonly) NSString *SECURE_STATE __attribute__((swift_name("SECURE_STATE")));
@property (readonly) NSString *SECURE_WRITE __attribute__((swift_name("SECURE_WRITE")));
@property (readonly) NSString *SERIAL_NUMBER __attribute__((swift_name("SERIAL_NUMBER")));
@property (readonly) NSString *TOTAL_UPLOADED_BYTES __attribute__((swift_name("TOTAL_UPLOADED_BYTES")));
@property (readonly) NSString *WRITE_WITHOUT_RESPONSE __attribute__((swift_name("WRITE_WITHOUT_RESPONSE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueConfig")))
@interface HardwareMirabilisBlueConfig : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mirabilisBlueConfig __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueConfig *shared __attribute__((swift_name("shared")));
- (NSArray<HardwareBleFilterNamePrefix *> *)bleFilter __attribute__((swift_name("bleFilter()")));
@property (readonly) NSString *advertisedName __attribute__((swift_name("advertisedName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueServices")))
@interface HardwareMirabilisBlueServices : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mirabilisBlueServices __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueServices *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *DEVICE_INFORMATION __attribute__((swift_name("DEVICE_INFORMATION")));
@property (readonly) NSString *TUTORIAL __attribute__((swift_name("TUTORIAL")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueDevice")))
@interface HardwareMirabilisBlueDevice : HardwareBleDevice
- (instancetype)initWithClient:(id<HardwareBleClient>)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(id<HardwareBleClient>)client liveInfo:(BOOL)liveInfo __attribute__((swift_name("init(client:liveInfo:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinException")))
@interface HardwareKotlinException : HardwareKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("MirabilisBlueError")))
@interface HardwareMirabilisBlueError : HardwareKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.EmptyFile")))
@interface HardwareMirabilisBlueErrorEmptyFile : HardwareMirabilisBlueError
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)emptyFile __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueErrorEmptyFile *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.FileTooLarge")))
@interface HardwareMirabilisBlueErrorFileTooLarge : HardwareMirabilisBlueError
- (instancetype)initWithActual:(int32_t)actual maximum:(int32_t)maximum __attribute__((swift_name("init(actual:maximum:)"))) __attribute__((objc_designated_initializer));
- (HardwareMirabilisBlueErrorFileTooLarge *)doCopyActual:(int32_t)actual maximum:(int32_t)maximum __attribute__((swift_name("doCopy(actual:maximum:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t actual __attribute__((swift_name("actual")));
@property (readonly) int32_t maximum __attribute__((swift_name("maximum")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.MalformedPacket")))
@interface HardwareMirabilisBlueErrorMalformedPacket : HardwareMirabilisBlueError
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)malformedPacket __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueErrorMalformedPacket *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.NegativeAcknowledgement")))
@interface HardwareMirabilisBlueErrorNegativeAcknowledgement : HardwareMirabilisBlueError
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)negativeAcknowledgement __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueErrorNegativeAcknowledgement *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.TransferCancelled")))
@interface HardwareMirabilisBlueErrorTransferCancelled : HardwareMirabilisBlueError
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)transferCancelled __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueErrorTransferCancelled *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueError.TransferInProgress")))
@interface HardwareMirabilisBlueErrorTransferInProgress : HardwareMirabilisBlueError
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)transferInProgress __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareMirabilisBlueErrorTransferInProgress *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferProtocol")))
@interface HardwareFileTransferProtocol : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)fileTransferProtocol __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareFileTransferProtocol *shared __attribute__((swift_name("shared")));
- (NSArray<HardwareFileTransferProtocolChunk *> *)chunksData:(HardwareKotlinByteArray *)data __attribute__((swift_name("chunks(data:)")));
- (HardwareKotlinByteArray *)uploadCommandSize:(int32_t)size __attribute__((swift_name("uploadCommand(size:)")));
@property (readonly) int8_t ACK __attribute__((swift_name("ACK")));
@property (readonly) int8_t CANCEL __attribute__((swift_name("CANCEL")));
@property (readonly) int8_t DOWNLOAD __attribute__((swift_name("DOWNLOAD")));
@property (readonly) int8_t END __attribute__((swift_name("END")));
@property (readonly) int8_t NACK __attribute__((swift_name("NACK")));
@property (readonly) int8_t START __attribute__((swift_name("START")));
@property (readonly) int8_t UPLOAD __attribute__((swift_name("UPLOAD")));
@property (readonly) int32_t acknowledgementInterval __attribute__((swift_name("acknowledgementInterval")));
@property (readonly) int32_t maximumFileSize __attribute__((swift_name("maximumFileSize")));
@property (readonly) int32_t maximumPacketSize __attribute__((swift_name("maximumPacketSize")));
@property (readonly) int32_t maximumPayloadSize __attribute__((swift_name("maximumPayloadSize")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferProtocol.Chunk")))
@interface HardwareFileTransferProtocolChunk : HardwareBase
- (instancetype)initWithMarker:(int8_t)marker sequence:(uint8_t)sequence payload:(HardwareKotlinByteArray *)payload __attribute__((swift_name("init(marker:sequence:payload:)"))) __attribute__((objc_designated_initializer));
- (HardwareFileTransferProtocolChunk *)doCopyMarker:(int8_t)marker sequence:(uint8_t)sequence payload:(HardwareKotlinByteArray *)payload __attribute__((swift_name("doCopy(marker:sequence:payload:)")));
- (HardwareKotlinByteArray *)encode __attribute__((swift_name("encode()")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int8_t marker __attribute__((swift_name("marker")));
@property (readonly) HardwareKotlinByteArray *payload __attribute__((swift_name("payload")));
@property (readonly) uint8_t sequence __attribute__((swift_name("sequence")));
@end

__attribute__((swift_name("FileTransferState")))
@protocol HardwareFileTransferState
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateCancelled")))
@interface HardwareFileTransferStateCancelled : HardwareBase <HardwareFileTransferState>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cancelled __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareFileTransferStateCancelled *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateCompleted")))
@interface HardwareFileTransferStateCompleted : HardwareBase <HardwareFileTransferState>
- (instancetype)initWithData:(HardwareKotlinByteArray * _Nullable)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
- (HardwareFileTransferStateCompleted *)doCopyData:(HardwareKotlinByteArray * _Nullable)data __attribute__((swift_name("doCopy(data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) HardwareKotlinByteArray * _Nullable data __attribute__((swift_name("data")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateDownloading")))
@interface HardwareFileTransferStateDownloading : HardwareBase <HardwareFileTransferState>
- (instancetype)initWithBytesTransferred:(int32_t)bytesTransferred __attribute__((swift_name("init(bytesTransferred:)"))) __attribute__((objc_designated_initializer));
- (HardwareFileTransferStateDownloading *)doCopyBytesTransferred:(int32_t)bytesTransferred __attribute__((swift_name("doCopy(bytesTransferred:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bytesTransferred __attribute__((swift_name("bytesTransferred")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateFailed")))
@interface HardwareFileTransferStateFailed : HardwareBase <HardwareFileTransferState>
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (HardwareFileTransferStateFailed *)doCopyMessage:(NSString *)message __attribute__((swift_name("doCopy(message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateIdle")))
@interface HardwareFileTransferStateIdle : HardwareBase <HardwareFileTransferState>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)idle __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareFileTransferStateIdle *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileTransferStateUploading")))
@interface HardwareFileTransferStateUploading : HardwareBase <HardwareFileTransferState>
- (instancetype)initWithBytesTransferred:(int32_t)bytesTransferred totalBytes:(int32_t)totalBytes __attribute__((swift_name("init(bytesTransferred:totalBytes:)"))) __attribute__((objc_designated_initializer));
- (HardwareFileTransferStateUploading *)doCopyBytesTransferred:(int32_t)bytesTransferred totalBytes:(int32_t)totalBytes __attribute__((swift_name("doCopy(bytesTransferred:totalBytes:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bytesTransferred __attribute__((swift_name("bytesTransferred")));
@property (readonly) int32_t totalBytes __attribute__((swift_name("totalBytes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MirabilisBlueService")))
@interface HardwareMirabilisBlueService : HardwareBleService<HardwareMirabilisBlueDevice *>
- (instancetype)initWithMock:(BOOL)mock __attribute__((swift_name("init(mock:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (HardwareMirabilisBlueDevice * _Nullable)clientToClient:(id<HardwareBleClient> _Nullable)client __attribute__((swift_name("clientTo(client:)")));
- (id<HardwareBleScan>)getScan __attribute__((swift_name("getScan()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogProvider")))
@interface HardwareLogProvider : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)logProvider __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareLogProvider *shared __attribute__((swift_name("shared")));
- (void)setup __attribute__((swift_name("setup()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProvideScope")))
@interface HardwareProvideScope : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)provideScope __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareProvideScope *shared __attribute__((swift_name("shared")));
@end

@interface HardwareBleDevice (Extensions)
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))connect __attribute__((swift_name("connect()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))disconnect __attribute__((swift_name("disconnect()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBleDeviceState *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getState __attribute__((swift_name("getState()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))isConnected __attribute__((swift_name("isConnected()")));
@end

@interface HardwareBleService (Extensions)
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(NSSet<HardwareBleDevice *> *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getDevices __attribute__((swift_name("getDevices()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBleScanState *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getState __attribute__((swift_name("getState()")));
@end

@interface HardwareBleFilter (Extensions)
- (HardwareCoreFilterNamePrefix *)toFilter __attribute__((swift_name("toFilter()")));
@end

@interface HardwareBleWriteType (Extensions)
- (HardwareCoreWriteType *)toWriteType __attribute__((swift_name("toWriteType()")));
@end

@interface HardwareKableClient (Extensions)
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))isClosed __attribute__((swift_name("isClosed()")));
@end

@interface HardwareMirabilisBlueDevice (Extensions)
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))cancelFileTransfer __attribute__((swift_name("cancelFileTransfer()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))download __attribute__((swift_name("download()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(id<HardwareFileTransferState>, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getFileTransferState __attribute__((swift_name("getFileTransferState()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))observePeriodicEvents __attribute__((swift_name("observePeriodicEvents()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))observeSecureState __attribute__((swift_name("observeSecureState()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))observeValue __attribute__((swift_name("observeValue()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readFirmwareRevision __attribute__((swift_name("readFirmwareRevision()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readHardwareRevision __attribute__((swift_name("readHardwareRevision()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readLastWriteWithoutResponseValue __attribute__((swift_name("readLastWriteWithoutResponseValue()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readLastWrittenValue __attribute__((swift_name("readLastWrittenValue()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readSecureState __attribute__((swift_name("readSecureState()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readSerialNumber __attribute__((swift_name("readSerialNumber()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareULong * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readTotalUploadedBytes __attribute__((swift_name("readTotalUploadedBytes()")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))secureWriteValue:(HardwareKotlinByteArray *)value __attribute__((swift_name("secureWrite(value:)")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))uploadData:(HardwareKotlinByteArray *)data __attribute__((swift_name("upload(data:)")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))writeBasicValue:(HardwareKotlinByteArray *)value __attribute__((swift_name("writeBasic(value:)")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))writeObservableValue:(HardwareKotlinByteArray *)value __attribute__((swift_name("writeObservable(value:)")));
- (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))writeWithoutResponseValue:(HardwareKotlinByteArray *)value __attribute__((swift_name("writeWithoutResponse(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface HardwareKotlinByteArray : HardwareBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(HardwareByte *(^)(HardwareInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (HardwareKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface HardwareKotlinByteArray (Extensions)
- (NSData *)toNSData __attribute__((swift_name("toNSData()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleClientNativeKt")))
@interface HardwareBleClientNativeKt : HardwareBase
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBleDeviceState *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))state:(id<HardwareBleClient>)receiver __attribute__((swift_name("state(_:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))connect:(id<HardwareBleClient>)receiver __attribute__((swift_name("connect(_:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))disconnect:(id<HardwareBleClient>)receiver __attribute__((swift_name("disconnect(_:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))isConnected:(id<HardwareBleClient>)receiver __attribute__((swift_name("isConnected(_:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))observeCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic __attribute__((swift_name("observeCharacteristic(_:characteristic:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))observeCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic onSubscription:(void (^ _Nullable)(void))onSubscription __attribute__((swift_name("observeCharacteristic(_:characteristic:onSubscription:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinByteArray * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))readCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic __attribute__((swift_name("readCharacteristic(_:characteristic:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))safeObserverCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic isSuccess:(HardwareBoolean *(^)(HardwareKotlinByteArray *))isSuccess __attribute__((swift_name("safeObserverCharacteristic(_:characteristic:isSuccess:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))safeReadCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic __attribute__((swift_name("safeReadCharacteristic(_:characteristic:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareKotlinUnit *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))safeWriteCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic byteArray:(HardwareKotlinByteArray *)byteArray writeType:(HardwareBleWriteType *)writeType __attribute__((swift_name("safeWriteCharacteristic(_:characteristic:byteArray:writeType:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBoolean *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))writeCharacteristic:(id<HardwareBleClient>)receiver characteristic:(NSString * _Nullable)characteristic byteArray:(HardwareKotlinByteArray *)byteArray writeType:(HardwareBleWriteType *)writeType __attribute__((swift_name("writeCharacteristic(_:characteristic:byteArray:writeType:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleScanNativeKt")))
@interface HardwareBleScanNativeKt : HardwareBase
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(id<HardwareBleClient> _Nullable, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getClients:(id<HardwareBleScan>)receiver __attribute__((swift_name("getClients(_:)")));
+ (HardwareKotlinUnit *(^(^)(HardwareKotlinUnit *(^)(HardwareBleScanState *, HardwareKotlinUnit *(^)(void), HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError * _Nullable, HardwareKotlinUnit *), HardwareKotlinUnit *(^)(NSError *, HardwareKotlinUnit *)))(void))getState:(id<HardwareBleScan>)receiver __attribute__((swift_name("getState(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NSDataConverterKt")))
@interface HardwareNSDataConverterKt : HardwareBase
+ (HardwareKotlinByteArray *)toByteArray:(NSData *)receiver __attribute__((swift_name("toByteArray(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ble_extensionsKt")))
@interface HardwareBle_extensionsKt : HardwareBase
+ (id<HardwareKotlinx_coroutines_coreJob>)addToList:(id<HardwareKotlinx_coroutines_coreJob>)receiver jobs:(NSMutableArray<id<HardwareKotlinx_coroutines_coreJob>> *)jobs __attribute__((swift_name("addToList(_:jobs:)")));
+ (void)checkBleOperation:(BOOL)receiver __attribute__((swift_name("checkBleOperation(_:)")));
+ (HardwareKotlinByteArray *)toMinimalByteArray:(int64_t)receiver __attribute__((swift_name("toMinimalByteArray(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EmitWhenKt")))
@interface HardwareEmitWhenKt : HardwareBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)emitWhen:(id<HardwareKotlinx_coroutines_coreMutableStateFlow>)receiver toAdd:(id _Nullable)toAdd predicate:(HardwareBoolean *(^)(id _Nullable))predicate completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emitWhen(_:toAdd:predicate:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogKt")))
@interface HardwareLogKt : HardwareBase
+ (void)logDebugValue:(NSString *)value __attribute__((swift_name("logDebug(value:)")));
+ (void)logErrorValue:(NSString *)value __attribute__((swift_name("logError(value:)")));
+ (void)logInfoValue:(NSString *)value __attribute__((swift_name("logInfo(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResumeOrCancelKt")))
@interface HardwareResumeOrCancelKt : HardwareBase
+ (void)cancelWhenActive:(id<HardwareKotlinx_coroutines_coreCancellableContinuation>)receiver value:(HardwareKotlinThrowable * _Nullable)value __attribute__((swift_name("cancelWhenActive(_:value:)")));
+ (void)resumeWhenActive:(id<HardwareKotlinx_coroutines_coreCancellableContinuation>)receiver value:(id _Nullable)value __attribute__((swift_name("resumeWhenActive(_:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface HardwareKotlinArray<T> : HardwareBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(HardwareInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<HardwareKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UuidUuid")))
@interface HardwareUuidUuid : HardwareBase <HardwareKotlinComparable>
- (instancetype)initWithUuidBytes:(HardwareKotlinByteArray *)uuidBytes __attribute__((swift_name("init(uuidBytes:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("Use `uuidOf` instead.")));
- (instancetype)initWithMsb:(int64_t)msb lsb:(int64_t)lsb __attribute__((swift_name("init(msb:lsb:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(HardwareUuidUuid *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t leastSignificantBits __attribute__((swift_name("leastSignificantBits")));
@property (readonly) int64_t mostSignificantBits __attribute__((swift_name("mostSignificantBits")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface HardwareKotlinEnumCompanion : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("CorePeripheral")))
@protocol HardwareCorePeripheral
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)connectWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("connect(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("disconnect(completionHandler:)")));
- (id<HardwareKotlinx_coroutines_coreFlow>)observeCharacteristic:(id<HardwareCoreCharacteristic>)characteristic onSubscription:(id<HardwareKotlinSuspendFunction0>)onSubscription __attribute__((swift_name("observe(characteristic:onSubscription:)")));

/**
 * @note This method converts instances of CancellationException, IOException, NotReadyException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readCharacteristic:(id<HardwareCoreCharacteristic>)characteristic completionHandler:(void (^)(HardwareKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("read(characteristic:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException, IOException, NotReadyException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readDescriptor:(id<HardwareCoreDescriptor>)descriptor completionHandler:(void (^)(HardwareKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("read(descriptor:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException, IOException, NotReadyException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)rssiWithCompletionHandler:(void (^)(HardwareInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("rssi(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException, IOException, NotReadyException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeDescriptor:(id<HardwareCoreDescriptor>)descriptor data:(HardwareKotlinByteArray *)data completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("write(descriptor:data:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException, IOException, NotReadyException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeCharacteristic:(id<HardwareCoreCharacteristic>)characteristic data:(HardwareKotlinByteArray *)data writeType:(HardwareCoreWriteType *)writeType completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("write(characteristic:data:writeType:completionHandler:)")));
@property (readonly) HardwareUuidUuid *identifier __attribute__((swift_name("identifier")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));
@property (readonly) NSArray<HardwareCoreDiscoveredService *> * _Nullable services __attribute__((swift_name("services")));
@property (readonly) id<HardwareKotlinx_coroutines_coreStateFlow> state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface HardwareKotlinPair<__covariant A, __covariant B> : HardwareBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (HardwareKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface HardwareKotlinUnit : HardwareBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("CoreFilter")))
@interface HardwareCoreFilter : HardwareBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreFilter.NamePrefix")))
@interface HardwareCoreFilterNamePrefix : HardwareCoreFilter
- (instancetype)initWithPrefix:(NSString *)prefix __attribute__((swift_name("init(prefix:)"))) __attribute__((objc_designated_initializer));
- (HardwareCoreFilterNamePrefix *)doCopyPrefix:(NSString *)prefix __attribute__((swift_name("doCopy(prefix:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *prefix __attribute__((swift_name("prefix")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreWriteType")))
@interface HardwareCoreWriteType : HardwareKotlinEnum<HardwareCoreWriteType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) HardwareCoreWriteType *withresponse __attribute__((swift_name("withresponse")));
@property (class, readonly) HardwareCoreWriteType *withoutresponse __attribute__((swift_name("withoutresponse")));
+ (HardwareKotlinArray<HardwareCoreWriteType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<HardwareCoreWriteType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol HardwareKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface HardwareKotlinByteIterator : HardwareBase <HardwareKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (HardwareByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol HardwareKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<HardwareKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<HardwareKotlinCoroutineContextElement> _Nullable)getKey:(id<HardwareKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<HardwareKotlinCoroutineContext>)minusKeyKey:(id<HardwareKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<HardwareKotlinCoroutineContext>)plusContext:(id<HardwareKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol HardwareKotlinCoroutineContextElement <HardwareKotlinCoroutineContext>
@required
@property (readonly) id<HardwareKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol HardwareKotlinx_coroutines_coreJob <HardwareKotlinCoroutineContextElement>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<HardwareKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<HardwareKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(HardwareKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (HardwareKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<HardwareKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(HardwareKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<HardwareKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(HardwareKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<HardwareKotlinx_coroutines_coreJob>)plusOther:(id<HardwareKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<HardwareKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<HardwareKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<HardwareKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface HardwareKotlinRuntimeException : HardwareKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface HardwareKotlinIllegalStateException : HardwareKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface HardwareKotlinCancellationException : HardwareKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol HardwareKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<HardwareKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol HardwareKotlinx_coroutines_coreSharedFlow <HardwareKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreStateFlow")))
@protocol HardwareKotlinx_coroutines_coreStateFlow <HardwareKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol HardwareKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutableSharedFlow")))
@protocol HardwareKotlinx_coroutines_coreMutableSharedFlow <HardwareKotlinx_coroutines_coreSharedFlow, HardwareKotlinx_coroutines_coreFlowCollector>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(id _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@property (readonly) id<HardwareKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutableStateFlow")))
@protocol HardwareKotlinx_coroutines_coreMutableStateFlow <HardwareKotlinx_coroutines_coreStateFlow, HardwareKotlinx_coroutines_coreMutableSharedFlow>
@required
- (void)setValue:(id _Nullable)value __attribute__((swift_name("setValue(_:)")));
- (BOOL)compareAndSetExpect:(id _Nullable)expect update:(id _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol HardwareKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<HardwareKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCancellableContinuation")))
@protocol HardwareKotlinx_coroutines_coreCancellableContinuation <HardwareKotlinContinuation>
@required
- (BOOL)cancelCause_:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)completeResumeToken:(id)token __attribute__((swift_name("completeResume(token:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)doInitCancellability __attribute__((swift_name("doInitCancellability()")));
- (void)invokeOnCancellationHandler:(void (^)(HardwareKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCancellation(handler:)")));
- (void)resumeValue:(id _Nullable)value onCancellation:(void (^ _Nullable)(HardwareKotlinThrowable *, id _Nullable, id<HardwareKotlinCoroutineContext>))onCancellation __attribute__((swift_name("resume(value:onCancellation:)")));
- (void)resumeValue:(id _Nullable)value onCancellation_:(void (^ _Nullable)(HardwareKotlinThrowable *))onCancellation __attribute__((swift_name("resume(value:onCancellation_:)"))) __attribute__((deprecated("Use the overload that also accepts the `value` and the coroutine context in lambda")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resumeUndispatched:(HardwareKotlinx_coroutines_coreCoroutineDispatcher *)receiver value:(id _Nullable)value __attribute__((swift_name("resumeUndispatched(_:value:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resumeUndispatchedWithException:(HardwareKotlinx_coroutines_coreCoroutineDispatcher *)receiver exception:(HardwareKotlinThrowable *)exception __attribute__((swift_name("resumeUndispatchedWithException(_:exception:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeValue:(id _Nullable)value idempotent:(id _Nullable)idempotent __attribute__((swift_name("tryResume(value:idempotent:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeValue:(id _Nullable)value idempotent:(id _Nullable)idempotent onCancellation:(void (^ _Nullable)(HardwareKotlinThrowable *, id _Nullable, id<HardwareKotlinCoroutineContext>))onCancellation __attribute__((swift_name("tryResume(value:idempotent:onCancellation:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeWithExceptionException:(HardwareKotlinThrowable *)exception __attribute__((swift_name("tryResumeWithException(exception:)")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@end

__attribute__((swift_name("ExceptionsIOException")))
@interface HardwareExceptionsIOException : HardwareKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("ExceptionsNotConnectedException")))
@interface HardwareExceptionsNotConnectedException : HardwareExceptionsIOException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExceptionsNotReadyException")))
@interface HardwareExceptionsNotReadyException : HardwareExceptionsNotConnectedException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(HardwareKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("CoreCharacteristic")))
@protocol HardwareCoreCharacteristic
@required
@property (readonly) HardwareUuidUuid *characteristicUuid __attribute__((swift_name("characteristicUuid")));
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol HardwareKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction0")))
@protocol HardwareKotlinSuspendFunction0 <HardwareKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(completionHandler:)")));
@end

__attribute__((swift_name("CoreDescriptor")))
@protocol HardwareCoreDescriptor
@required
@property (readonly) HardwareUuidUuid *characteristicUuid __attribute__((swift_name("characteristicUuid")));
@property (readonly) HardwareUuidUuid *descriptorUuid __attribute__((swift_name("descriptorUuid")));
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end

__attribute__((swift_name("CoreService")))
@protocol HardwareCoreService
@required
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreDiscoveredService")))
@interface HardwareCoreDiscoveredService : HardwareBase <HardwareCoreService>
- (HardwareCoreDiscoveredService *)doCopyService:(CBService *)service __attribute__((swift_name("doCopy(service:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<HardwareCoreDiscoveredCharacteristic *> *characteristics __attribute__((swift_name("characteristics")));
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol HardwareKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol HardwareKotlinx_coroutines_coreChildHandle <HardwareKotlinx_coroutines_coreDisposableHandle>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BOOL)childCancelledCause:(HardwareKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) id<HardwareKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol HardwareKotlinx_coroutines_coreChildJob <HardwareKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)parentCancelledParentJob:(id<HardwareKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol HardwareKotlinSequence
@required
- (id<HardwareKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol HardwareKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) HardwareKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<HardwareKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(HardwareKotlinThrowable *, id _Nullable, id<HardwareKotlinCoroutineContext>) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<HardwareKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol HardwareKotlinx_coroutines_coreSelectClause0 <HardwareKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol HardwareKotlinCoroutineContextKey
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface HardwareKotlinAbstractCoroutineContextElement : HardwareBase <HardwareKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<HardwareKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<HardwareKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol HardwareKotlinContinuationInterceptor <HardwareKotlinCoroutineContextElement>
@required
- (id<HardwareKotlinContinuation>)interceptContinuationContinuation:(id<HardwareKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<HardwareKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface HardwareKotlinx_coroutines_coreCoroutineDispatcher : HardwareKotlinAbstractCoroutineContextElement <HardwareKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<HardwareKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) HardwareKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<HardwareKotlinCoroutineContext>)context block:(id<HardwareKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)dispatchYieldContext:(id<HardwareKotlinCoroutineContext>)context block:(id<HardwareKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<HardwareKotlinContinuation>)interceptContinuationContinuation:(id<HardwareKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<HardwareKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));
- (HardwareKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism name:(NSString * _Nullable)name __attribute__((swift_name("limitedParallelism(parallelism:name:)")));
- (HardwareKotlinx_coroutines_coreCoroutineDispatcher *)plusOther_:(HardwareKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<HardwareKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreDiscoveredCharacteristic")))
@interface HardwareCoreDiscoveredCharacteristic : HardwareBase <HardwareCoreCharacteristic>
- (HardwareCoreDiscoveredCharacteristic *)doCopyCharacteristic:(CBCharacteristic *)characteristic __attribute__((swift_name("doCopy(characteristic:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) HardwareUuidUuid *characteristicUuid __attribute__((swift_name("characteristicUuid")));
@property (readonly) NSArray<HardwareCoreDiscoveredDescriptor *> *descriptors __attribute__((swift_name("descriptors")));
@property (readonly) int32_t properties __attribute__((swift_name("properties")));
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol HardwareKotlinx_coroutines_coreParentJob <HardwareKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (HardwareKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol HardwareKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<HardwareKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<HardwareKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface HardwareKotlinAbstractCoroutineContextKey<B, E> : HardwareBase <HardwareKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<HardwareKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<HardwareKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface HardwareKotlinx_coroutines_coreCoroutineDispatcherKey : HardwareKotlinAbstractCoroutineContextKey<id<HardwareKotlinContinuationInterceptor>, HardwareKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<HardwareKotlinCoroutineContextKey>)baseKey safeCast:(id<HardwareKotlinCoroutineContextElement> _Nullable (^)(id<HardwareKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) HardwareKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol HardwareKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreDiscoveredDescriptor")))
@interface HardwareCoreDiscoveredDescriptor : HardwareBase <HardwareCoreDescriptor>
- (HardwareCoreDiscoveredDescriptor *)doCopyDescriptor:(CBDescriptor *)descriptor __attribute__((swift_name("doCopy(descriptor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) HardwareUuidUuid *characteristicUuid __attribute__((swift_name("characteristicUuid")));
@property (readonly) HardwareUuidUuid *descriptorUuid __attribute__((swift_name("descriptorUuid")));
@property (readonly) HardwareUuidUuid *serviceUuid __attribute__((swift_name("serviceUuid")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
