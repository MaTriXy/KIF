//
//  KIFUIViewActor.h
//  KIF
//
//  Created by Alex Odawa on 1/21/15.
//
//

#import <KIF/KIF.h>

#define viewTester KIFActorWithClass(KIFUIViewTestActor)


@interface KIFUIViewTestActor : KIFTestActor

@property (nonatomic, strong, readonly) UIView *view;
@property (nonatomic, strong, readonly) UIAccessibilityElement *element;
@property (nonatomic, strong, readonly) NSPredicate *predicate;

- (instancetype)usingPredicate:(NSPredicate *)predicate;
- (instancetype)usingLabel:(NSString *)accessibilityLabel;
- (instancetype)usingIdentifier:(NSString *)accessibilityIdentifier;
- (instancetype)usingTraits:(UIAccessibilityTraits)accessibilityTraits;
- (instancetype)usingValue:(NSString *)accessibilityValue;

- (void)tap;
- (void)longPress;
- (void)longPressWithDuration:(NSTimeInterval)duration;

- (void)tapScreenAtPoint:(CGPoint)screenPoint;
- (void)swipeInDirection:(KIFSwipeDirection)direction;

- (UIView *)waitForView;
- (void)waitForAbsenceOfView;
- (void)waitToBecomeTappable;
- (void)waitToBecomeFirstResponder;

- (BOOL)tryFindingView;
- (BOOL)tryFindingTappableView;

- (void)enterText:(NSString *)text;
- (void)enterText:(NSString *)text expectedResult:(NSString *)expectedResult;
- (void)enterTextIntoCurrentFirstResponder:(NSString *)text;
- (void)enterTextIntoCurrentFirstResponder:(NSString *)text fallbackView:(UIView *)fallbackView;

- (void)clearText;
- (void)clearTextFromFirstResponder;
- (void)clearAndEnterText:(NSString *)text;
- (void)clearAndEnterText:(NSString *)text expectedResult:(NSString *)expectedResult;

- (void)waitForSoftwareKeyboard;
- (void)waitForAbsenceOfSoftwareKeyboard;
- (void)waitForKeyInputReady;

- (void)setSliderValue:(float)value;
- (void)setSwitchOn:(BOOL)switchIsOn;

- (void)tapRowInTableViewAtIndexPath:(NSIndexPath *)indexPath;
- (UITableViewCell *)waitForCellInTableViewAtIndexPath:(NSIndexPath *)indexPath;
- (void)moveRowInTableViewAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;

- (void)tapCollectionViewItemAtIndexPath:(NSIndexPath *)indexPath;
- (UICollectionViewCell *)waitForCellInCollectionViewAtIndexPath:(NSIndexPath *)indexPath;

- (void)scrollByFractionOfSizeHorizontal:(CGFloat)horizontalFraction vertical:(CGFloat)verticalFraction;

- (void)selectPickerViewRowWithTitle:(NSString *)title;
- (void)selectPickerViewRowWithTitle:(NSString *)title inComponent:(NSInteger)component;
- (void)selectDatePickerValue:(NSArray *)datePickerColumnValues;
- (void)choosePhotoInAlbum:(NSString *)albumName atRow:(NSInteger)row column:(NSInteger)column;

- (void)tapStatusBar;
- (void)dismissPopover;

- (void)pullToRefresh;
- (void)pullToRefreshWithDuration:(KIFPullToRefreshTiming)pullDownDuration;

#if TARGET_IPHONE_SIMULATOR
- (BOOL)acknowledgeSystemAlert;
#endif


@end
