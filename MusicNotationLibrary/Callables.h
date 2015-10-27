@import Foundation;

typedef NSString* (^CALLABLE_TO_STRING)(id);
typedef NSNumber* (^CALLABLE_TO_NUMBER)(id);
typedef NSString* (^ACCUMULATOR_TO_STRING)(id, id);

@interface Callables : NSObject
+ (NSString* (^)(NSString*))toUpperCase;

+ (NSString* (^)(NSString*, NSString*))appendString;

+ (ACCUMULATOR_TO_STRING)appendWithSeparator:(NSString*)separator;

+ (CALLABLE_TO_STRING)upperCase;

+ (CALLABLE_TO_NUMBER)increment;
@end

inline static CALLABLE_TO_STRING TL_upperCase()
{
    return [Callables upperCase];
}

inline static ACCUMULATOR_TO_STRING TL_appendWithSeparator(NSString* separator)
{
    return [Callables appendWithSeparator:separator];
}

inline static CALLABLE_TO_NUMBER TL_increment()
{
    return [Callables increment];
}
