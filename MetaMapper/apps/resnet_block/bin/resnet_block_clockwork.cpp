#include <iostream>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

extern "C" {
int64_t halide_current_time_ns(void *ctx);
void halide_profiler_pipeline_end(void *, void *);
}

#ifdef _WIN32
__declspec(dllimport) float __cdecl roundf(float);
__declspec(dllimport) double __cdecl round(double);
#else
inline float asinh_f32(float x) {return asinhf(x);}
inline float acosh_f32(float x) {return acoshf(x);}
inline float atanh_f32(float x) {return atanhf(x);}
inline double asinh_f64(double x) {return asinh(x);}
inline double acosh_f64(double x) {return acosh(x);}
inline double atanh_f64(double x) {return atanh(x);}
#endif
inline float sqrt_f32(float x) {return sqrtf(x);}
inline float sin_f32(float x) {return sinf(x);}
inline float asin_f32(float x) {return asinf(x);}
inline float cos_f32(float x) {return cosf(x);}
inline float acos_f32(float x) {return acosf(x);}
inline float tan_f32(float x) {return tanf(x);}
inline float atan_f32(float x) {return atanf(x);}
inline float sinh_f32(float x) {return sinhf(x);}
inline float cosh_f32(float x) {return coshf(x);}
inline float tanh_f32(float x) {return tanhf(x);}
inline float hypot_f32(float x, float y) {return hypotf(x, y);}
inline float exp_f32(float x) {return expf(x);}
inline float log_f32(float x) {return logf(x);}
inline float pow_f32(float x, float y) {return powf(x, y);}
inline float floor_f32(float x) {return floorf(x);}
inline float ceil_f32(float x) {return ceilf(x);}
inline float round_f32(float x) {return roundf(x);}

inline double sqrt_f64(double x) {return sqrt(x);}
inline double sin_f64(double x) {return sin(x);}
inline double asin_f64(double x) {return asin(x);}
inline double cos_f64(double x) {return cos(x);}
inline double acos_f64(double x) {return acos(x);}
inline double tan_f64(double x) {return tan(x);}
inline double atan_f64(double x) {return atan(x);}
inline double sinh_f64(double x) {return sinh(x);}
inline double cosh_f64(double x) {return cosh(x);}
inline double tanh_f64(double x) {return tanh(x);}
inline double hypot_f64(double x, double y) {return hypot(x, y);}
inline double exp_f64(double x) {return exp(x);}
inline double log_f64(double x) {return log(x);}
inline double pow_f64(double x, double y) {return pow(x, y);}
inline double floor_f64(double x) {return floor(x);}
inline double ceil_f64(double x) {return ceil(x);}
inline double round_f64(double x) {return round(x);}

inline float nan_f32() {return NAN;}
inline float neg_inf_f32() {return -INFINITY;}
inline float inf_f32() {return INFINITY;}
inline bool is_nan_f32(float x) {return x != x;}
inline bool is_nan_f64(double x) {return x != x;}

template<typename A, typename B>
inline A reinterpret(const B &b) {
    #if __cplusplus >= 201103L
    static_assert(sizeof(A) == sizeof(B), "type size mismatch");
    #endif
    A a;
    memcpy(&a, &b, sizeof(a));
    return a;
}
inline float float_from_bits(uint32_t bits) {
    return reinterpret<float, uint32_t>(bits);
}

union {
  uint32_t val;
  float f;
} union_var;


namespace {
struct bfloat16_t {

    static const int mantissa_bits = 7;
    static const uint16_t sign_mask = 0x8000;
    static const uint16_t exponent_mask = 0x7f80;
    static const uint16_t mantissa_mask = 0x007f;

    /// \name Constructors
    /// @{

    /** Construct from a float, double, or int using
     * round-to-nearest-ties-to-even. Out-of-range values become +/-
     * infinity.
     */
    // @{
    explicit bfloat16_t(float value);
    explicit bfloat16_t(double value);
    explicit bfloat16_t(int value);
    bfloat16_t(uint16_t value);
    // @}

    /** Construct a bfloat16_t with the bits initialised to 0. This represents
     * positive zero.*/
    bfloat16_t() = default;

    /// @}

    // Use explicit to avoid accidently raising the precision
    /** Cast to float */
    explicit operator float() const;
    /** Cast to double */
    explicit operator double() const;
    /** Cast to int */
    explicit operator int() const;
    operator uint16_t() const;

    /** \name Convenience "constructors"
     */
    /**@{*/

    /** Get a new bfloat16_t that represents zero
     * \param positive if true then returns positive zero otherwise returns
     *        negative zero.
     */
    static bfloat16_t make_zero(bool positive);

    /** Get a new float16_t that represents infinity
     * \param positive if true then returns positive infinity otherwise returns
     *        negative infinity.
     */
    static bfloat16_t make_infinity(bool positive);

    /** Get a new bfloat16_t that represents NaN (not a number) */
    static bfloat16_t make_nan();

    /** Get a new bfloat16_t with the given raw bits
     *
     * \param bits The bits conformant to IEEE754 binary16
     */
    static bfloat16_t make_from_bits(uint16_t bits);

    /**@}*/

    /** Return a new bfloat16_t with a negated sign bit*/
    bfloat16_t operator-() const;

    /** Arithmetic operators. */
    // @{
    bfloat16_t operator+(bfloat16_t rhs) const;
    bfloat16_t operator-(bfloat16_t rhs) const;
    bfloat16_t operator*(bfloat16_t rhs) const;
    bfloat16_t operator/(bfloat16_t rhs) const;
    bfloat16_t operator+=(bfloat16_t rhs) { return (*this = *this + rhs); }
    bfloat16_t operator-=(bfloat16_t rhs) { return (*this = *this - rhs); }
    bfloat16_t operator*=(bfloat16_t rhs) { return (*this = *this * rhs); }
    bfloat16_t operator/=(bfloat16_t rhs) { return (*this = *this / rhs); }
    // @}

    /** Comparison operators */
    // @{
    bool operator==(bfloat16_t rhs) const;
    bool operator!=(bfloat16_t rhs) const { return !(*this == rhs); }
    bool operator>(bfloat16_t rhs) const;
    bool operator<(bfloat16_t rhs) const;
    bool operator>=(bfloat16_t rhs) const { return (*this > rhs) || (*this == rhs); }
    bool operator<=(bfloat16_t rhs) const { return (*this < rhs) || (*this == rhs); }
    // @}

    /** Properties */
    // @{
    bool is_nan() const;
    bool is_infinity() const;
    bool is_negative() const;
    bool is_zero() const;
    // @}

    /** Returns the bits that represent this bfloat16_t.
     *
     *  An alternative method to access the bits is to cast a pointer
     *  to this instance as a pointer to a uint16_t.
     **/
    uint16_t to_bits() const;

private:
    // The raw bits.
    uint16_t data = 0;
};

uint16_t round_to_even(float a) {
  //uint32_t e = reinterpret_cast<uint32_t&>(a);
  union_var.f = a;
  uint32_t e = union_var.val;
  
  // round float to even, comment out this codeblock for truncation
  uint32_t half = 0x00008000;
  uint32_t sum = e + half;
  
  // check if bottom bits are all zero
  uint32_t mantissa_mask = 0x0000ffff;
  bool is_zeroed = (sum & mantissa_mask) == 0;
  
  // clear last bit (round even) on tie
  uint32_t clear_mask = ~( ((uint32_t)is_zeroed) << 16);
  e = sum & clear_mask;

  // clear bottom bits
  e = e >> 16;

  //return bfloat16_t::make_from_bits(float_to_bfloat16( expf(bfloat16_to_float(a.to_bits())) ));
  //return bfloat16_t::make_from_bits( (uint16_t)e );
  return (uint16_t)e;
}

//static inline
//bfloat16_t int_to_float(const hw_uint<16>& in) {
//  return (bfloat16_t) in.to_int();
//}
//
//static inline
//bfloat16_t to_float(const hw_uint<16>& in) {
//  int i = in.to_int();
//  void* ip = (void*)(&i);
//  float* f = (float*) ip;
//  return (*f);
//}

// Similar routines for bfloat. It's somewhat simpler.
uint16_t float_to_bfloat16(float f) {
    //uint16_t ret[2];
    //memcpy(ret, &f, sizeof(float));
    //// Assume little-endian floats
    //return ret[1];
    return round_to_even(f);
}

float bfloat16_to_float(uint16_t b) {
    // Assume little-endian floats
    uint16_t bits[2] = {0, b};
    float ret;
    memcpy(&ret, bits, sizeof(float));
    return ret;
}

bfloat16_t::bfloat16_t(float value) : data(float_to_bfloat16(value)) {}

bfloat16_t::bfloat16_t(double value) : data(float_to_bfloat16(value)) {}

bfloat16_t::bfloat16_t(int value) : data(float_to_bfloat16(value)) {}

bfloat16_t::bfloat16_t(uint16_t value) : data(value) {}

bfloat16_t::operator float() const {
    return bfloat16_to_float(data);
}

bfloat16_t::operator double() const {
    return bfloat16_to_float(data);
}

bfloat16_t::operator int() const {
    return bfloat16_to_float(data);
}

bfloat16_t::operator uint16_t() const {
    return data;
}


bfloat16_t bfloat16_t::make_from_bits(uint16_t bits) {
    bfloat16_t f;
    f.data = bits;
    return f;
}

bfloat16_t bfloat16_t::make_zero(bool positive) {
    uint16_t bits = positive ? 0 : sign_mask;
    return bfloat16_t::make_from_bits(bits);
}

bfloat16_t bfloat16_t::make_infinity(bool positive) {
    uint16_t bits = exponent_mask | (positive ? 0 : sign_mask);
    return bfloat16_t::make_from_bits(bits);
}

bfloat16_t bfloat16_t::make_nan() {
    uint16_t bits = exponent_mask | mantissa_mask;
    return bfloat16_t::make_from_bits(bits);
}

bfloat16_t bfloat16_t::operator-() const {
    return bfloat16_t(-bfloat16_to_float(data));
}

bfloat16_t bfloat16_t::operator+(bfloat16_t rhs) const {
    return bfloat16_t(bfloat16_to_float(data) + bfloat16_to_float(rhs.data));
}

bfloat16_t bfloat16_t::operator-(bfloat16_t rhs) const {
    return bfloat16_t(bfloat16_to_float(data) - bfloat16_to_float(rhs.data));
}

bfloat16_t bfloat16_t::operator*(bfloat16_t rhs) const {
    return bfloat16_t(bfloat16_to_float(data) * bfloat16_to_float(rhs.data));
}

bfloat16_t bfloat16_t::operator/(bfloat16_t rhs) const {
    return bfloat16_t(bfloat16_to_float(data) / bfloat16_to_float(rhs.data));
}

bool bfloat16_t::operator==(bfloat16_t rhs) const {
    return bfloat16_to_float(data) == bfloat16_to_float(rhs.data);
}

bool bfloat16_t::operator>(bfloat16_t rhs) const {
    return bfloat16_to_float(data) > bfloat16_to_float(rhs.data);
}

bool bfloat16_t::operator<(bfloat16_t rhs) const {
    return bfloat16_to_float(data) < bfloat16_to_float(rhs.data);
}

bool bfloat16_t::is_nan() const {
    return ((data & exponent_mask) == exponent_mask) && (data & mantissa_mask);
}

bool bfloat16_t::is_infinity() const {
    return ((data & exponent_mask) == exponent_mask) && !(data & mantissa_mask);
}

bool bfloat16_t::is_negative() const {
    return data & sign_mask;
}

bool bfloat16_t::is_zero() const {
    return !(data & ~sign_mask);
}

uint16_t bfloat16_t::to_bits() const {
    return data;
}

static
inline bfloat16_t bfloat_from_bits(uint32_t bits) {
    return bfloat16_t(float_from_bits(bits));
}
}

template<typename T>
inline int halide_popcount(T a) {
    int bits_set = 0;
    while (a != 0) {
        bits_set += a & 1;
        a >>= 1;
    }
    return bits_set;
}

template<typename T>
inline int halide_count_leading_zeros(T a) {
    int leading_zeros = 0;
    int bit = sizeof(a) * 8 - 1;
    while (bit >= 0 && (a & (((T)1) << bit)) == 0) {
        leading_zeros++;
        bit--;
    }
    return leading_zeros;
}

template<typename T>
inline int halide_count_trailing_zeros(T a) {
    int trailing_zeros = 0;
    constexpr int bits = sizeof(a) * 8;
    int bit = 0;
    while (bit < bits && (a & (((T)1) << bit)) == 0) {
        trailing_zeros++;
        bit++;
    }
    return trailing_zeros;
}

template<typename T>
inline T halide_cpp_max(const T &a, const T &b) {return (a > b) ? a : b;}

template<typename T>
inline T halide_cpp_min(const T &a, const T &b) {return (a < b) ? a : b;}

template<typename A, typename B>
const B &return_second(const A &a, const B &b) {
    (void) a;
    return b;
}

template<typename A, typename B>
inline auto quiet_div(const A &a, const B &b) -> decltype(a / b) {
    return b == 0 ? static_cast<decltype(a / b)>(0) : (a / b);
}

template<typename A, typename B>
inline auto quiet_mod(const A &a, const B &b) -> decltype(a % b) {
    return b == 0 ? static_cast<decltype(a % b)>(0) : (a % b);
}

namespace {
class HalideFreeHelper {
    typedef void (*FreeFunction)(void *user_context, void *p);
    void * user_context;
    void *p;
    FreeFunction free_function;
public:
    HalideFreeHelper(void *user_context, void *p, FreeFunction free_function)
        : user_context(user_context), p(p), free_function(free_function) {}
    ~HalideFreeHelper() { free(); }
    void free() {
        if (p) {
            // TODO: do all free_functions guarantee to ignore a nullptr?
            free_function(user_context, p);
            p = nullptr;
        }
    }
};
} // namespace

#ifndef HALIDE_HALIDERUNTIME_H
#define HALIDE_HALIDERUNTIME_H

#ifndef COMPILING_HALIDE_RUNTIME
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#else
#include "runtime_internal.h"
#endif

#ifdef __cplusplus
// Forward declare type to allow naming typed handles.
// See Type.h for documentation.
template<typename T> struct halide_handle_traits;
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Note that you should not use "inline" along with HALIDE_ALWAYS_INLINE;
// it is not necessary, and may produce warnings for some build configurations.
#ifdef _MSC_VER
#define HALIDE_ALWAYS_INLINE __forceinline
#define HALIDE_NEVER_INLINE __declspec(noinline)
#else
#define HALIDE_ALWAYS_INLINE __attribute__((always_inline)) inline
#define HALIDE_NEVER_INLINE __attribute__((noinline))
#endif

/** \file
 *
 * This file declares the routines used by Halide internally in its
 * runtime. On platforms that support weak linking, these can be
 * replaced with user-defined versions by defining an extern "C"
 * function with the same name and signature.
 *
 * When doing Just In Time (JIT) compilation methods on the Func being
 * compiled must be called instead. The corresponding methods are
 * documented below.
 *
 * All of these functions take a "void *user_context" parameter as their
 * first argument; if the Halide kernel that calls back to any of these
 * functions has been compiled with the UserContext feature set on its Target,
 * then the value of that pointer passed from the code that calls the
 * Halide kernel is piped through to the function.
 *
 * Some of these are also useful to call when using the default
 * implementation. E.g. halide_shutdown_thread_pool.
 *
 * Note that even on platforms with weak linking, some linker setups
 * may not respect the override you provide. E.g. if the override is
 * in a shared library and the halide object files are linked directly
 * into the output, the builtin versions of the runtime functions will
 * be called. See your linker documentation for more details. On
 * Linux, LD_DYNAMIC_WEAK=1 may help.
 *
 */

// Forward-declare to suppress warnings if compiling as C.
struct halide_buffer_t;
struct buffer_t;

/** Print a message to stderr. Main use is to support tracing
 * functionality, print, and print_when calls. Also called by the default
 * halide_error.  This function can be replaced in JITed code by using
 * halide_custom_print and providing an implementation of halide_print
 * in AOT code. See Func::set_custom_print.
 */
// @{
extern void halide_print(void *user_context, const char *);
extern void halide_default_print(void *user_context, const char *);
typedef void (*halide_print_t)(void *, const char *);
extern halide_print_t halide_set_custom_print(halide_print_t print);
// @}

/** Halide calls this function on runtime errors (for example bounds
 * checking failures). This function can be replaced in JITed code by
 * using Func::set_error_handler, or in AOT code by calling
 * halide_set_error_handler. In AOT code on platforms that support
 * weak linking (i.e. not Windows), you can also override it by simply
 * defining your own halide_error.
 */
// @{
extern void halide_error(void *user_context, const char *);
extern void halide_default_error(void *user_context, const char *);
typedef void (*halide_error_handler_t)(void *, const char *);
extern halide_error_handler_t halide_set_error_handler(halide_error_handler_t handler);
// @}

/** Cross-platform mutex. Must be initialized with zero and implementation
 * must treat zero as an unlocked mutex with no waiters, etc.
 */
struct halide_mutex {
    uintptr_t _private[1];
};

/** Cross platform condition variable. Must be initialized to 0. */
struct halide_cond {
    uintptr_t _private[1];
};

/** A basic set of mutex and condition variable functions, which call
 * platform specific code for mutual exclusion. Equivalent to posix
 * calls. */
//@{
extern void halide_mutex_lock(struct halide_mutex *mutex);
extern void halide_mutex_unlock(struct halide_mutex *mutex);
extern void halide_cond_signal(struct halide_cond *cond);
extern void halide_cond_broadcast(struct halide_cond *cond);
extern void halide_cond_signal(struct halide_cond *cond);
extern void halide_cond_wait(struct halide_cond *cond, struct halide_mutex *mutex);
//@}

/** Define halide_do_par_for to replace the default thread pool
 * implementation. halide_shutdown_thread_pool can also be called to
 * release resources used by the default thread pool on platforms
 * where it makes sense. (E.g. On Mac OS, Grand Central Dispatch is
 * used so %Halide does not own the threads backing the pool and they
 * cannot be released.)  See Func::set_custom_do_task and
 * Func::set_custom_do_par_for. Should return zero if all the jobs
 * return zero, or an arbitrarily chosen return value from one of the
 * jobs otherwise.
 */
//@{
typedef int (*halide_task_t)(void *user_context, int task_number, uint8_t *closure);
extern int halide_do_par_for(void *user_context,
                             halide_task_t task,
                             int min, int size, uint8_t *closure);
extern void halide_shutdown_thread_pool();
//@}

/** Set a custom method for performing a parallel for loop. Returns
 * the old do_par_for handler. */
typedef int (*halide_do_par_for_t)(void *, halide_task_t, int, int, uint8_t*);
extern halide_do_par_for_t halide_set_custom_do_par_for(halide_do_par_for_t do_par_for);

/** An opaque struct representing a semaphore. Used by the task system for async tasks. */
struct halide_semaphore_t {
    uint64_t _private[2];
};

/** A struct representing a semaphore and a number of items that must
 * be acquired from it. Used in halide_parallel_task_t below. */
struct halide_semaphore_acquire_t {
    struct halide_semaphore_t *semaphore;
    int count;
};
extern int halide_semaphore_init(struct halide_semaphore_t *, int n);
extern int halide_semaphore_release(struct halide_semaphore_t *, int n);
extern bool halide_semaphore_try_acquire(struct halide_semaphore_t *, int n);
typedef int (*halide_semaphore_init_t)(struct halide_semaphore_t *, int);
typedef int (*halide_semaphore_release_t)(struct halide_semaphore_t *, int);
typedef bool (*halide_semaphore_try_acquire_t)(struct halide_semaphore_t *, int);


/** A task representing a serial for loop evaluated over some range.
 * Note that task_parent is a pass through argument that should be
 * passed to any dependent taks that are invokved using halide_do_parallel_tasks
 * underneath this call. */
typedef int (*halide_loop_task_t)(void *user_context, int min, int extent,
                                  uint8_t *closure, void *task_parent);

/** A parallel task to be passed to halide_do_parallel_tasks. This
 * task may recursively call halide_do_parallel_tasks, and there may
 * be complex dependencies between seemingly unrelated tasks expressed
 * using semaphores. If you are using a custom task system, care must
 * be taken to avoid potential deadlock. This can be done by carefully
 * respecting the static metadata at the end of the task struct.*/
struct halide_parallel_task_t {
    // The function to call. It takes a user context, a min and
    // extent, a closure, and a task system pass through argument.
    halide_loop_task_t fn;

    // The closure to pass it
    uint8_t *closure;

    // The name of the function to be called. For debugging purposes only.
    const char *name;

    // An array of semaphores that must be acquired before the
    // function is called. Must be reacquired for every call made.
    struct halide_semaphore_acquire_t *semaphores;
    int num_semaphores;

    // The entire range the function should be called over. This range
    // may be sliced up and the function called multiple times.
    int min, extent;

    // A parallel task provides several pieces of metadata to prevent
    // unbounded resource usage or deadlock.

    // The first is the minimum number of execution contexts (call
    // stacks or threads) necessary for the function to run to
    // completion. This may be greater than one when there is nested
    // parallelism with internal producer-consumer relationships
    // (calling the function recursively spawns and blocks on parallel
    // sub-tasks that communicate with each other via semaphores). If
    // a parallel runtime calls the function when fewer than this many
    // threads are idle, it may need to create more threads to
    // complete the task, or else risk deadlock due to committing all
    // threads to tasks that cannot complete without more.
    //
    // FIXME: Note that extern stages are assumed to only require a
    // single thread to complete. If the extern stage is itself a
    // Halide pipeline, this may be an underestimate.
    int min_threads;

    // The calls to the function should be in serial order from min to min+extent-1, with only
    // one executing at a time. If false, any order is fine, and
    // concurrency is fine.
    bool serial;
};

/** Enqueue some number of the tasks described above and wait for them
 * to complete. While waiting, the calling threads assists with either
 * the tasks enqueued, or other non-blocking tasks in the task
 * system. Note that task_parent should be NULL for top-level calls
 * and the pass through argument if this call is being made from
 * another task. */
extern int halide_do_parallel_tasks(void *user_context, int num_tasks,
                                    struct halide_parallel_task_t *tasks,
                                    void *task_parent);

/** If you use the default do_par_for, you can still set a custom
 * handler to perform each individual task. Returns the old handler. */
//@{
typedef int (*halide_do_task_t)(void *, halide_task_t, int, uint8_t *);
extern halide_do_task_t halide_set_custom_do_task(halide_do_task_t do_task);
extern int halide_do_task(void *user_context, halide_task_t f, int idx,
                          uint8_t *closure);
//@}

/** The version of do_task called for loop tasks. By default calls the
 * loop task with the same arguments. */
// @{
  typedef int (*halide_do_loop_task_t)(void *, halide_loop_task_t, int, int, uint8_t *, void *);
extern halide_do_loop_task_t halide_set_custom_do_loop_task(halide_do_loop_task_t do_task);
extern int halide_do_loop_task(void *user_context, halide_loop_task_t f, int min, int extent,
                               uint8_t *closure, void *task_parent);
//@}

/** Provide an entire custom tasking runtime via function
 * pointers. Note that do_task and semaphore_try_acquire are only ever
 * called by halide_default_do_par_for and
 * halide_default_do_parallel_tasks, so it's only necessary to provide
 * those if you are mixing in the default implementations of
 * do_par_for and do_parallel_tasks. */
// @{
typedef int (*halide_do_parallel_tasks_t)(void *, int, struct halide_parallel_task_t *,
                                          void *task_parent);
extern void halide_set_custom_parallel_runtime(
    halide_do_par_for_t,
    halide_do_task_t,
    halide_do_loop_task_t,
    halide_do_parallel_tasks_t,
    halide_semaphore_init_t,
    halide_semaphore_try_acquire_t,
    halide_semaphore_release_t
    );
// @}

/** The default versions of the parallel runtime functions. */
// @{
extern int halide_default_do_par_for(void *user_context,
                                     halide_task_t task,
                                     int min, int size, uint8_t *closure);
extern int halide_default_do_parallel_tasks(void *user_context,
                                            int num_tasks,
                                            struct halide_parallel_task_t *tasks,
                                            void *task_parent);
extern int halide_default_do_task(void *user_context, halide_task_t f, int idx,
                                  uint8_t *closure);
extern int halide_default_do_loop_task(void *user_context, halide_loop_task_t f,
                                       int min, int extent,
                                       uint8_t *closure, void *task_parent);
extern int halide_default_semaphore_init(struct halide_semaphore_t *, int n);
extern int halide_default_semaphore_release(struct halide_semaphore_t *, int n);
extern bool halide_default_semaphore_try_acquire(struct halide_semaphore_t *, int n);
// @}

struct halide_thread;

/** Spawn a thread. Returns a handle to the thread for the purposes of
 * joining it. The thread must be joined in order to clean up any
 * resources associated with it. */
extern struct halide_thread *halide_spawn_thread(void (*f)(void *), void *closure);

/** Join a thread. */
extern void halide_join_thread(struct halide_thread *);

/** Set the number of threads used by Halide's thread pool. Returns
 * the old number.
 *
 * n < 0  : error condition
 * n == 0 : use a reasonable system default (typically, number of cpus online).
 * n == 1 : use exactly one thread; this will always enforce serial execution
 * n > 1  : use a pool of exactly n threads.
 *
 * (Note that this is only guaranteed when using the default implementations
 * of halide_do_par_for(); custom implementations may completely ignore values
 * passed to halide_set_num_threads().)
 */
extern int halide_set_num_threads(int n);

/** Halide calls these functions to allocate and free memory. To
 * replace in AOT code, use the halide_set_custom_malloc and
 * halide_set_custom_free, or (on platforms that support weak
 * linking), simply define these functions yourself. In JIT-compiled
 * code use Func::set_custom_allocator.
 *
 * If you override them, and find yourself wanting to call the default
 * implementation from within your override, use
 * halide_default_malloc/free.
 *
 * Note that halide_malloc must return a pointer aligned to the
 * maximum meaningful alignment for the platform for the purpose of
 * vector loads and stores. The default implementation uses 32-byte
 * alignment, which is safe for arm and x86. Additionally, it must be
 * safe to read at least 8 bytes before the start and beyond the
 * end.
 */
//@{
extern void *halide_malloc(void *user_context, size_t x);
extern void halide_free(void *user_context, void *ptr);
extern void *halide_default_malloc(void *user_context, size_t x);
extern void halide_default_free(void *user_context, void *ptr);
typedef void *(*halide_malloc_t)(void *, size_t);
typedef void (*halide_free_t)(void *, void *);
extern halide_malloc_t halide_set_custom_malloc(halide_malloc_t user_malloc);
extern halide_free_t halide_set_custom_free(halide_free_t user_free);
//@}

/** Halide calls these functions to interact with the underlying
 * system runtime functions. To replace in AOT code on platforms that
 * support weak linking, define these functions yourself, or use
 * the halide_set_custom_load_library() and halide_set_custom_get_library_symbol()
 * functions. In JIT-compiled code, use JITSharedRuntime::set_default_handlers().
 *
 * halide_load_library and halide_get_library_symbol are equivalent to
 * dlopen and dlsym. halide_get_symbol(sym) is equivalent to
 * dlsym(RTLD_DEFAULT, sym).
 */
//@{
extern void *halide_get_symbol(const char *name);
extern void *halide_load_library(const char *name);
extern void *halide_get_library_symbol(void *lib, const char *name);
extern void *halide_default_get_symbol(const char *name);
extern void *halide_default_load_library(const char *name);
extern void *halide_default_get_library_symbol(void *lib, const char *name);
typedef void *(*halide_get_symbol_t)(const char *name);
typedef void *(*halide_load_library_t)(const char *name);
typedef void *(*halide_get_library_symbol_t)(void *lib, const char *name);
extern halide_get_symbol_t halide_set_custom_get_symbol(halide_get_symbol_t user_get_symbol);
extern halide_load_library_t halide_set_custom_load_library(halide_load_library_t user_load_library);
extern halide_get_library_symbol_t halide_set_custom_get_library_symbol(halide_get_library_symbol_t user_get_library_symbol);
//@}

/** Called when debug_to_file is used inside %Halide code.  See
 * Func::debug_to_file for how this is called
 *
 * Cannot be replaced in JITted code at present.
 */
extern int32_t halide_debug_to_file(void *user_context, const char *filename,
                                    int32_t type_code,
                                    struct halide_buffer_t *buf);

/** Types in the halide type system. They can be ints, unsigned ints,
 * or floats (of various bit-widths), or a handle (which is always 64-bits).
 * Note that the int/uint/float values do not imply a specific bit width
 * (the bit width is expected to be encoded in a separate value).
 */
typedef enum halide_type_code_t
#if __cplusplus >= 201103L
: uint8_t
#endif
{
    halide_type_int = 0,   //!< signed integers
    halide_type_uint = 1,  //!< unsigned integers
    halide_type_float = 2, //!< IEEE floating point numbers
    halide_type_handle = 3, //!< opaque pointer type (void *)
    halide_type_bfloat = 4, //!< floating point numbers in the bfloat format
} halide_type_code_t;

// Note that while __attribute__ can go before or after the declaration,
// __declspec apparently is only allowed before.
#ifndef HALIDE_ATTRIBUTE_ALIGN
    #ifdef _MSC_VER
        #define HALIDE_ATTRIBUTE_ALIGN(x) __declspec(align(x))
    #else
        #define HALIDE_ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
    #endif
#endif

/** A runtime tag for a type in the halide type system. Can be ints,
 * unsigned ints, or floats of various bit-widths (the 'bits'
 * field). Can also be vectors of the same (by setting the 'lanes'
 * field to something larger than one). This struct should be
 * exactly 32-bits in size. */
struct halide_type_t {
    /** The basic type code: signed integer, unsigned integer, or floating point. */
#if __cplusplus >= 201103L
    HALIDE_ATTRIBUTE_ALIGN(1) halide_type_code_t code; // halide_type_code_t
#else
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t code; // halide_type_code_t
#endif

    /** The number of bits of precision of a single scalar value of this type. */
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t bits;

    /** How many elements in a vector. This is 1 for scalar types. */
    HALIDE_ATTRIBUTE_ALIGN(2) uint16_t lanes;

#ifdef __cplusplus
    /** Construct a runtime representation of a Halide type from:
     * code: The fundamental type from an enum.
     * bits: The bit size of one element.
     * lanes: The number of vector elements in the type. */
    HALIDE_ALWAYS_INLINE halide_type_t(halide_type_code_t code, uint8_t bits, uint16_t lanes = 1)
        : code(code), bits(bits), lanes(lanes) {
    }

    /** Default constructor is required e.g. to declare halide_trace_event
     * instances. */
    HALIDE_ALWAYS_INLINE halide_type_t() : code((halide_type_code_t)0), bits(0), lanes(0) {}

    /** Compare two types for equality. */
    HALIDE_ALWAYS_INLINE bool operator==(const halide_type_t &other) const {
        return as_u32() == other.as_u32();
    }

    HALIDE_ALWAYS_INLINE bool operator!=(const halide_type_t &other) const {
        return !(*this == other);
    }

    HALIDE_ALWAYS_INLINE bool operator<(const halide_type_t &other) const {
        return as_u32() < other.as_u32();
    }

    /** Size in bytes for a single element, even if width is not 1, of this type. */
    HALIDE_ALWAYS_INLINE int bytes() const { return (bits + 7) / 8; }

    HALIDE_ALWAYS_INLINE uint32_t as_u32() const {
        uint32_t u;
        memcpy(&u, this, sizeof(u));
        return u;
    }
#endif
};

enum halide_trace_event_code_t {halide_trace_load = 0,
                                halide_trace_store = 1,
                                halide_trace_begin_realization = 2,
                                halide_trace_end_realization = 3,
                                halide_trace_produce = 4,
                                halide_trace_end_produce = 5,
                                halide_trace_consume = 6,
                                halide_trace_end_consume = 7,
                                halide_trace_begin_pipeline = 8,
                                halide_trace_end_pipeline = 9,
                                halide_trace_tag = 10 };

struct halide_trace_event_t {
    /** The name of the Func or Pipeline that this event refers to */
    const char *func;

    /** If the event type is a load or a store, this points to the
     * value being loaded or stored. Use the type field to safely cast
     * this to a concrete pointer type and retrieve it. For other
     * events this is null. */
    void *value;

    /** For loads and stores, an array which contains the location
     * being accessed. For vector loads or stores it is an array of
     * vectors of coordinates (the vector dimension is innermost).
     *
     * For realization or production-related events, this will contain
     * the mins and extents of the region being accessed, in the order
     * min0, extent0, min1, extent1, ...
     *
     * For pipeline-related events, this will be null.
     */
    int32_t *coordinates;

    /** For halide_trace_tag, this points to a read-only null-terminated string
     * of arbitrary text. For all other events, this will be null.
     */
    const char *trace_tag;

    /** If the event type is a load or a store, this is the type of
     * the data. Otherwise, the value is meaningless. */
    struct halide_type_t type;

    /** The type of event */
    enum halide_trace_event_code_t event;

    /* The ID of the parent event (see below for an explanation of
     * event ancestry). */
    int32_t parent_id;

    /** If this was a load or store of a Tuple-valued Func, this is
     * which tuple element was accessed. */
    int32_t value_index;

    /** The length of the coordinates array */
    int32_t dimensions;

#ifdef __cplusplus
    // If we don't explicitly mark the default ctor as inline,
    // certain build configurations can fail (notably iOS)
    HALIDE_ALWAYS_INLINE halide_trace_event_t() {}
#endif
};

/** Called when Funcs are marked as trace_load, trace_store, or
 * trace_realization. See Func::set_custom_trace. The default
 * implementation either prints events via halide_print, or if
 * HL_TRACE_FILE is defined, dumps the trace to that file in a
 * sequence of trace packets. The header for a trace packet is defined
 * below. If the trace is going to be large, you may want to make the
 * file a named pipe, and then read from that pipe into gzip.
 *
 * halide_trace returns a unique ID which will be passed to future
 * events that "belong" to the earlier event as the parent id. The
 * ownership hierarchy looks like:
 *
 * begin_pipeline
 * +--trace_tag (if any)
 * +--trace_tag (if any)
 * ...
 * +--begin_realization
 * |  +--produce
 * |  |  +--load/store
 * |  |  +--end_produce
 * |  +--consume
 * |  |  +--load
 * |  |  +--end_consume
 * |  +--end_realization
 * +--end_pipeline
 *
 * Threading means that ownership cannot be inferred from the ordering
 * of events. There can be many active realizations of a given
 * function, or many active productions for a single
 * realization. Within a single production, the ordering of events is
 * meaningful.
 *
 * Note that all trace_tag events (if any) will occur just after the begin_pipeline
 * event, but before any begin_realization events. All trace_tags for a given Func
 * will be emitted in the order added.
 */
// @}
extern int32_t halide_trace(void *user_context, const struct halide_trace_event_t *event);
extern int32_t halide_default_trace(void *user_context, const struct halide_trace_event_t *event);
typedef int32_t (*halide_trace_t)(void *user_context, const struct halide_trace_event_t *);
extern halide_trace_t halide_set_custom_trace(halide_trace_t trace);
// @}

/** The header of a packet in a binary trace. All fields are 32-bit. */
struct halide_trace_packet_t {
    /** The total size of this packet in bytes. Always a multiple of
     * four. Equivalently, the number of bytes until the next
     * packet. */
    uint32_t size;

    /** The id of this packet (for the purpose of parent_id). */
    int32_t id;

    /** The remaining fields are equivalent to those in halide_trace_event_t */
    // @{
    struct halide_type_t type;
    enum halide_trace_event_code_t event;
    int32_t parent_id;
    int32_t value_index;
    int32_t dimensions;
    // @}

    #ifdef __cplusplus
    // If we don't explicitly mark the default ctor as inline,
    // certain build configurations can fail (notably iOS)
    HALIDE_ALWAYS_INLINE halide_trace_packet_t() {}

    /** Get the coordinates array, assuming this packet is laid out in
     * memory as it was written. The coordinates array comes
     * immediately after the packet header. */
    HALIDE_ALWAYS_INLINE const int *coordinates() const {
        return (const int *)(this + 1);
    }

    HALIDE_ALWAYS_INLINE int *coordinates() {
        return (int *)(this + 1);
    }

    /** Get the value, assuming this packet is laid out in memory as
     * it was written. The packet comes immediately after the coordinates
     * array. */
    HALIDE_ALWAYS_INLINE const void *value() const {
        return (const void *)(coordinates() + dimensions);
    }

    HALIDE_ALWAYS_INLINE void *value() {
        return (void *)(coordinates() + dimensions);
    }

    /** Get the func name, assuming this packet is laid out in memory
     * as it was written. It comes after the value. */
    HALIDE_ALWAYS_INLINE const char *func() const {
        return (const char *)value() + type.lanes * type.bytes();
    }

    HALIDE_ALWAYS_INLINE char *func() {
        return (char *)value() + type.lanes * type.bytes();
    }

    /** Get the trace_tag (if any), assuming this packet is laid out in memory
     * as it was written. It comes after the func name. If there is no trace_tag,
     * this will return a pointer to an empty string. */
    HALIDE_ALWAYS_INLINE const char *trace_tag() const {
        const char *f = func();
        // strlen may not be available here
        while (*f++) {
            // nothing
        }
        return f;
    }

    HALIDE_ALWAYS_INLINE char *trace_tag() {
        char *f = func();
        // strlen may not be available here
        while (*f++) {
            // nothing
        }
        return f;
    }
    #endif
};



/** Set the file descriptor that Halide should write binary trace
 * events to. If called with 0 as the argument, Halide outputs trace
 * information to stdout in a human-readable format. If never called,
 * Halide checks the for existence of an environment variable called
 * HL_TRACE_FILE and opens that file. If HL_TRACE_FILE is not defined,
 * it outputs trace information to stdout in a human-readable
 * format. */
extern void halide_set_trace_file(int fd);

/** Halide calls this to retrieve the file descriptor to write binary
 * trace events to. The default implementation returns the value set
 * by halide_set_trace_file. Implement it yourself if you wish to use
 * a custom file descriptor per user_context. Return zero from your
 * implementation to tell Halide to print human-readable trace
 * information to stdout. */
extern int halide_get_trace_file(void *user_context);

/** If tracing is writing to a file. This call closes that file
 * (flushing the trace). Returns zero on success. */
extern int halide_shutdown_trace();

/** All Halide GPU or device backend implementations provide an
 * interface to be used with halide_device_malloc, etc. This is
 * accessed via the functions below.
 */

/** An opaque struct containing per-GPU API implementations of the
 * device functions. */
struct halide_device_interface_impl_t;

/** Each GPU API provides a halide_device_interface_t struct pointing
 * to the code that manages device allocations. You can access these
 * functions directly from the struct member function pointers, or by
 * calling the functions declared below. Note that the global
 * functions are not available when using Halide as a JIT compiler.
 * If you are using raw halide_buffer_t in that context you must use
 * the function pointers in the device_interface struct.
 *
 * The function pointers below are currently the same for every GPU
 * API; only the impl field varies. These top-level functions do the
 * bookkeeping that is common across all GPU APIs, and then dispatch
 * to more API-specific functions via another set of function pointers
 * hidden inside the impl field.
 */
struct halide_device_interface_t {
    int (*device_malloc)(void *user_context, struct halide_buffer_t *buf,
                         const struct halide_device_interface_t *device_interface);
    int (*device_free)(void *user_context, struct halide_buffer_t *buf);
    int (*device_sync)(void *user_context, struct halide_buffer_t *buf);
    void (*device_release)(void *user_context,
                          const struct halide_device_interface_t *device_interface);
    int (*copy_to_host)(void *user_context, struct halide_buffer_t *buf);
    int (*copy_to_device)(void *user_context, struct halide_buffer_t *buf,
                          const struct halide_device_interface_t *device_interface);
    int (*device_and_host_malloc)(void *user_context, struct halide_buffer_t *buf,
                                  const struct halide_device_interface_t *device_interface);
    int (*device_and_host_free)(void *user_context, struct halide_buffer_t *buf);
    int (*buffer_copy)(void *user_context, struct halide_buffer_t *src,
                       const struct halide_device_interface_t *dst_device_interface, struct halide_buffer_t *dst);
    int (*device_crop)(void *user_context, const struct halide_buffer_t *src,
                       struct halide_buffer_t *dst);
    int (*device_slice)(void *user_context, const struct halide_buffer_t *src,
                        int slice_dim, int slice_pos, struct halide_buffer_t *dst);
    int (*device_release_crop)(void *user_context, struct halide_buffer_t *buf);
    int (*wrap_native)(void *user_context, struct halide_buffer_t *buf, uint64_t handle,
                       const struct halide_device_interface_t *device_interface);
    int (*detach_native)(void *user_context, struct halide_buffer_t *buf);
    int (*compute_capability)(void *user_context, int *major, int *minor);
    const struct halide_device_interface_impl_t *impl;
};

/** Release all data associated with the given device interface, in
 * particular all resources (memory, texture, context handles)
 * allocated by Halide. Must be called explicitly when using AOT
 * compilation. This is *not* thread-safe with respect to actively
 * running Halide code. Ensure all pipelines are finished before
 * calling this. */
extern void halide_device_release(void *user_context,
                                  const struct halide_device_interface_t *device_interface);

/** Copy image data from device memory to host memory. This must be called
 * explicitly to copy back the results of a GPU-based filter. */
extern int halide_copy_to_host(void *user_context, struct halide_buffer_t *buf);

/** Copy image data from host memory to device memory. This should not
 * be called directly; Halide handles copying to the device
 * automatically.  If interface is NULL and the buf has a non-zero dev
 * field, the device associated with the dev handle will be
 * used. Otherwise if the dev field is 0 and interface is NULL, an
 * error is returned. */
extern int halide_copy_to_device(void *user_context, struct halide_buffer_t *buf,
                                 const struct halide_device_interface_t *device_interface);

/** Copy data from one buffer to another. The buffers may have
 * different shapes and sizes, but the destination buffer's shape must
 * be contained within the source buffer's shape. That is, for each
 * dimension, the min on the destination buffer must be greater than
 * or equal to the min on the source buffer, and min+extent on the
 * destination buffer must be less that or equal to min+extent on the
 * source buffer. The source data is pulled from either device or
 * host memory on the source, depending on the dirty flags. host is
 * preferred if both are valid. The dst_device_interface parameter
 * controls the destination memory space. NULL means host memory. */
extern int halide_buffer_copy(void *user_context, struct halide_buffer_t *src,
                              const struct halide_device_interface_t *dst_device_interface,
                              struct halide_buffer_t *dst);

/** Give the destination buffer a device allocation which is an alias
 * for the same coordinate range in the source buffer. Modifies the
 * device, device_interface, and the device_dirty flag only. Only
 * supported by some device APIs (others will return
 * halide_error_code_device_crop_unsupported). Call
 * halide_device_release_crop instead of halide_device_free to clean
 * up resources associated with the cropped view. Do not free the
 * device allocation on the source buffer while the destination buffer
 * still lives. Note that the two buffers do not share dirty flags, so
 * care must be taken to update them together as needed. Note that src
 * and dst are required to have the same number of dimensions.
 *
 * Note also that (in theory) device interfaces which support cropping may
 * still not support cropping a crop (instead, create a new crop of the parent
 * buffer); in practice, no known implementation has this limitation, although
 * it is possible that some future implementations may require it. */
extern int halide_device_crop(void *user_context,
                              const struct halide_buffer_t *src,
                              struct halide_buffer_t *dst);

/** Give the destination buffer a device allocation which is an alias
 * for a similar coordinate range in the source buffer, but with one dimension
 * sliced away in the dst. Modifies the device, device_interface, and the
 * device_dirty flag only. Only supported by some device APIs (others will return
 * halide_error_code_device_crop_unsupported). Call
 * halide_device_release_crop instead of halide_device_free to clean
 * up resources associated with the sliced view. Do not free the
 * device allocation on the source buffer while the destination buffer
 * still lives. Note that the two buffers do not share dirty flags, so
 * care must be taken to update them together as needed. Note that the dst buffer
 * must have exactly one fewer dimension than the src buffer, and that slice_dim
 * and slice_pos must be valid within src. */
extern int halide_device_slice(void *user_context,
                               const struct halide_buffer_t *src,
                               int slice_dim, int slice_pos,
                               struct halide_buffer_t *dst);

/** Release any resources associated with a cropped/sliced view of another
 * buffer. */
extern int halide_device_release_crop(void *user_context,
                                      struct halide_buffer_t *buf);

/** Wait for current GPU operations to complete. Calling this explicitly
 * should rarely be necessary, except maybe for profiling. */
extern int halide_device_sync(void *user_context, struct halide_buffer_t *buf);

/** Allocate device memory to back a halide_buffer_t. */
extern int halide_device_malloc(void *user_context, struct halide_buffer_t *buf,
                                const struct halide_device_interface_t *device_interface);

/** Free device memory. */
extern int halide_device_free(void *user_context, struct halide_buffer_t *buf);

/** Wrap or detach a native device handle, setting the device field
 * and device_interface field as appropriate for the given GPU
 * API. The meaning of the opaque handle is specific to the device
 * interface, so if you know the device interface in use, call the
 * more specific functions in the runtime headers for your specific
 * device API instead (e.g. HalideRuntimeCuda.h). */
// @{
extern int halide_device_wrap_native(void *user_context,
                                     struct halide_buffer_t *buf,
                                     uint64_t handle,
                                     const struct halide_device_interface_t *device_interface);
extern int halide_device_detach_native(void *user_context, struct halide_buffer_t *buf);
// @}

/** Versions of the above functions that accept legacy buffer_t structs. */
// @{
extern int halide_copy_to_host_legacy(void *user_context, struct buffer_t *buf);
extern int halide_copy_to_device_legacy(void *user_context, struct buffer_t *buf,
                                 const struct halide_device_interface_t *device_interface);
extern int halide_device_sync_legacy(void *user_context, struct buffer_t *buf);
extern int halide_device_malloc_legacy(void *user_context, struct buffer_t *buf,
                                const struct halide_device_interface_t *device_interface);
extern int halide_device_free_legacy(void *user_context, struct buffer_t *buf);
// @}

/** Selects which gpu device to use. 0 is usually the display
 * device. If never called, Halide uses the environment variable
 * HL_GPU_DEVICE. If that variable is unset, Halide uses the last
 * device. Set this to -1 to use the last device. */
extern void halide_set_gpu_device(int n);

/** Halide calls this to get the desired halide gpu device
 * setting. Implement this yourself to use a different gpu device per
 * user_context. The default implementation returns the value set by
 * halide_set_gpu_device, or the environment variable
 * HL_GPU_DEVICE. */
extern int halide_get_gpu_device(void *user_context);

/** Set the soft maximum amount of memory, in bytes, that the LRU
 *  cache will use to memoize Func results.  This is not a strict
 *  maximum in that concurrency and simultaneous use of memoized
 *  reults larger than the cache size can both cause it to
 *  temporariliy be larger than the size specified here.
 */
extern void halide_memoization_cache_set_size(int64_t size);

/** Given a cache key for a memoized result, currently constructed
 *  from the Func name and top-level Func name plus the arguments of
 *  the computation, determine if the result is in the cache and
 *  return it if so. (The internals of the cache key should be
 *  considered opaque by this function.) If this routine returns true,
 *  it is a cache miss. Otherwise, it will return false and the
 *  buffers passed in will be filled, via copying, with memoized
 *  data. The last argument is a list if halide_buffer_t pointers which
 *  represents the outputs of the memoized Func. If the Func does not
 *  return a Tuple, there will only be one halide_buffer_t in the list. The
 *  tuple_count parameters determines the length of the list.
 *
 * The return values are:
 * -1: Signals an error.
 *  0: Success and cache hit.
 *  1: Success and cache miss.
 */
extern int halide_memoization_cache_lookup(void *user_context, const uint8_t *cache_key, int32_t size,
                                           struct halide_buffer_t *realized_bounds,
                                           int32_t tuple_count, struct halide_buffer_t **tuple_buffers);

/** Given a cache key for a memoized result, currently constructed
 *  from the Func name and top-level Func name plus the arguments of
 *  the computation, store the result in the cache for futre access by
 *  halide_memoization_cache_lookup. (The internals of the cache key
 *  should be considered opaque by this function.) Data is copied out
 *  from the inputs and inputs are unmodified. The last argument is a
 *  list if halide_buffer_t pointers which represents the outputs of the
 *  memoized Func. If the Func does not return a Tuple, there will
 *  only be one halide_buffer_t in the list. The tuple_count parameters
 *  determines the length of the list.
 *
 * If there is a memory allocation failure, the store does not store
 * the data into the cache.
 */
extern int halide_memoization_cache_store(void *user_context, const uint8_t *cache_key, int32_t size,
                                          struct halide_buffer_t *realized_bounds,
                                          int32_t tuple_count,
                                          struct halide_buffer_t **tuple_buffers);

/** If halide_memoization_cache_lookup succeeds,
 * halide_memoization_cache_release must be called to signal the
 * storage is no longer being used by the caller. It will be passed
 * the host pointer of one the buffers returned by
 * halide_memoization_cache_lookup. That is
 * halide_memoization_cache_release will be called multiple times for
 * the case where halide_memoization_cache_lookup is handling multiple
 * buffers.  (This corresponds to memoizing a Tuple in Halide.) Note
 * that the host pointer must be sufficient to get to all information
 * the relase operation needs. The default Halide cache impleemntation
 * accomplishes this by storing extra data before the start of the user
 * modifiable host storage.
 *
 * This call is like free and does not have a failure return.
  */
extern void halide_memoization_cache_release(void *user_context, void *host);

/** Free all memory and resources associated with the memoization cache.
 * Must be called at a time when no other threads are accessing the cache.
 */
extern void halide_memoization_cache_cleanup();

/** Create a unique file with a name of the form prefixXXXXXsuffix in an arbitrary
 * (but writable) directory; this is typically $TMP or /tmp, but the specific
 * location is not guaranteed. (Note that the exact form of the file name
 * may vary; in particular, the suffix may be ignored on non-Posix systems.)
 * The file is created (but not opened), thus this can be called from
 * different threads (or processes, e.g. when building with parallel make)
 * without risking collision. Note that the caller is always responsible
 * for deleting this file. Returns nonzero value if an error occurs.
 */
extern int halide_create_temp_file(void *user_context,
  const char *prefix, const char *suffix,
  char *path_buf, size_t path_buf_size);

/** Annotate that a given range of memory has been initialized;
 * only used when Target::MSAN is enabled.
 *
 * The default implementation uses the LLVM-provided AnnotateMemoryIsInitialized() function.
 */
extern void halide_msan_annotate_memory_is_initialized(void *user_context, const void *ptr, uint64_t len);

/** Mark the data pointed to by the buffer_t as initialized (but *not* the buffer_t itself),
 * using halide_msan_annotate_memory_is_initialized() for marking.
 *
 * The default implementation takes pains to only mark the active memory ranges
 * (skipping padding), and sorting into ranges to always mark the smallest number of
 * ranges, in monotonically increasing memory order.
 *
 * Most client code should never need to replace the default implementation.
 */
extern void halide_msan_annotate_buffer_is_initialized(void *user_context, struct halide_buffer_t *buffer);
extern void halide_msan_annotate_buffer_is_initialized_as_destructor(void *user_context, void *buffer);

/** The error codes that may be returned by a Halide pipeline. */
enum halide_error_code_t {
    /** There was no error. This is the value returned by Halide on success. */
    halide_error_code_success = 0,

    /** An uncategorized error occurred. Refer to the string passed to halide_error. */
    halide_error_code_generic_error = -1,

    /** A Func was given an explicit bound via Func::bound, but this
     * was not large enough to encompass the region that is used of
     * the Func by the rest of the pipeline. */
    halide_error_code_explicit_bounds_too_small = -2,

    /** The elem_size field of a halide_buffer_t does not match the size in
     * bytes of the type of that ImageParam. Probable type mismatch. */
    halide_error_code_bad_type = -3,

    /** A pipeline would access memory outside of the halide_buffer_t passed
     * in. */
    halide_error_code_access_out_of_bounds = -4,

    /** A halide_buffer_t was given that spans more than 2GB of memory. */
    halide_error_code_buffer_allocation_too_large = -5,

    /** A halide_buffer_t was given with extents that multiply to a number
     * greater than 2^31-1 */
    halide_error_code_buffer_extents_too_large = -6,

    /** Applying explicit constraints on the size of an input or
     * output buffer shrank the size of that buffer below what will be
     * accessed by the pipeline. */
    halide_error_code_constraints_make_required_region_smaller = -7,

    /** A constraint on a size or stride of an input or output buffer
     * was not met by the halide_buffer_t passed in. */
    halide_error_code_constraint_violated = -8,

    /** A scalar parameter passed in was smaller than its minimum
     * declared value. */
    halide_error_code_param_too_small = -9,

    /** A scalar parameter passed in was greater than its minimum
     * declared value. */
    halide_error_code_param_too_large = -10,

    /** A call to halide_malloc returned NULL. */
    halide_error_code_out_of_memory = -11,

    /** A halide_buffer_t pointer passed in was NULL. */
    halide_error_code_buffer_argument_is_null = -12,

    /** debug_to_file failed to open or write to the specified
     * file. */
    halide_error_code_debug_to_file_failed = -13,

    /** The Halide runtime encountered an error while trying to copy
     * from device to host. Turn on -debug in your target string to
     * see more details. */
    halide_error_code_copy_to_host_failed = -14,

    /** The Halide runtime encountered an error while trying to copy
     * from host to device. Turn on -debug in your target string to
     * see more details. */
    halide_error_code_copy_to_device_failed = -15,

    /** The Halide runtime encountered an error while trying to
     * allocate memory on device. Turn on -debug in your target string
     * to see more details. */
    halide_error_code_device_malloc_failed = -16,

    /** The Halide runtime encountered an error while trying to
     * synchronize with a device. Turn on -debug in your target string
     * to see more details. */
    halide_error_code_device_sync_failed = -17,

    /** The Halide runtime encountered an error while trying to free a
     * device allocation. Turn on -debug in your target string to see
     * more details. */
    halide_error_code_device_free_failed = -18,

    /** Buffer has a non-zero device but no device interface, which
     * violates a Halide invariant. */
    halide_error_code_no_device_interface = -19,

    /** An error occurred when attempting to initialize the Matlab
     * runtime. */
    halide_error_code_matlab_init_failed = -20,

    /** The type of an mxArray did not match the expected type. */
    halide_error_code_matlab_bad_param_type = -21,

    /** There is a bug in the Halide compiler. */
    halide_error_code_internal_error = -22,

    /** The Halide runtime encountered an error while trying to launch
     * a GPU kernel. Turn on -debug in your target string to see more
     * details. */
    halide_error_code_device_run_failed = -23,

    /** The Halide runtime encountered a host pointer that violated
     * the alignment set for it by way of a call to
     * set_host_alignment */
    halide_error_code_unaligned_host_ptr = -24,

    /** A fold_storage directive was used on a dimension that is not
     * accessed in a monotonically increasing or decreasing fashion. */
    halide_error_code_bad_fold = -25,

    /** A fold_storage directive was used with a fold factor that was
     * too small to store all the values of a producer needed by the
     * consumer. */
    halide_error_code_fold_factor_too_small = -26,

    /** User-specified require() expression was not satisfied. */
    halide_error_code_requirement_failed = -27,

    /** At least one of the buffer's extents are negative. */
    halide_error_code_buffer_extents_negative = -28,

    /** A compiled pipeline was passed the old deprecated buffer_t
     * struct, and it could not be upgraded to a halide_buffer_t. */
    halide_error_code_failed_to_upgrade_buffer_t = -29,

    /** A compiled pipeline was passed the old deprecated buffer_t
     * struct in bounds inference mode, but the returned information
     * can't be expressed in the old buffer_t. */
    halide_error_code_failed_to_downgrade_buffer_t = -30,

    /** A specialize_fail() schedule branch was selected at runtime. */
    halide_error_code_specialize_fail = -31,

    /** The Halide runtime encountered an error while trying to wrap a
     * native device handle.  Turn on -debug in your target string to
     * see more details. */
    halide_error_code_device_wrap_native_failed = -32,

    /** The Halide runtime encountered an error while trying to detach
     * a native device handle.  Turn on -debug in your target string
     * to see more details. */
    halide_error_code_device_detach_native_failed = -33,

    /** The host field on an input or output was null, the device
     * field was not zero, and the pipeline tries to use the buffer on
     * the host. You may be passing a GPU-only buffer to a pipeline
     * which is scheduled to use it on the CPU. */
    halide_error_code_host_is_null = -34,

    /** A folded buffer was passed to an extern stage, but the region
     * touched wraps around the fold boundary. */
    halide_error_code_bad_extern_fold = -35,

    /** Buffer has a non-null device_interface but device is 0, which
     * violates a Halide invariant. */
    halide_error_code_device_interface_no_device= -36,

    /** Buffer has both host and device dirty bits set, which violates
     * a Halide invariant. */
    halide_error_code_host_and_device_dirty = -37,

    /** The halide_buffer_t * passed to a halide runtime routine is
     * nullptr and this is not allowed. */
    halide_error_code_buffer_is_null = -38,

    /** The Halide runtime encountered an error while trying to copy
     * from one buffer to another. Turn on -debug in your target
     * string to see more details. */
    halide_error_code_device_buffer_copy_failed = -39,

    /** Attempted to make cropped/sliced alias of a buffer with a device
     * field, but the device_interface does not support cropping. */
    halide_error_code_device_crop_unsupported = -40,

    /** Cropping/slicing a buffer failed for some other reason. Turn on -debug
     * in your target string. */
    halide_error_code_device_crop_failed = -41,

    /** An operation on a buffer required an allocation on a
     * particular device interface, but a device allocation already
     * existed on a different device interface. Free the old one
     * first. */
    halide_error_code_incompatible_device_interface = -42,

    /** The dimensions field of a halide_buffer_t does not match the dimensions of that ImageParam. */
    halide_error_code_bad_dimensions = -43,

    /** An expression that would perform an integer division or modulo
     * by zero was evaluated. */
    halide_error_code_integer_division_by_zero = -44,

};

/** Halide calls the functions below on various error conditions. The
 * default implementations construct an error message, call
 * halide_error, then return the matching error code above. On
 * platforms that support weak linking, you can override these to
 * catch the errors individually. */

/** A call into an extern stage for the purposes of bounds inference
 * failed. Returns the error code given by the extern stage. */
extern int halide_error_bounds_inference_call_failed(void *user_context, const char *extern_stage_name, int result);

/** A call to an extern stage failed. Returned the error code given by
 * the extern stage. */
extern int halide_error_extern_stage_failed(void *user_context, const char *extern_stage_name, int result);

/** Various other error conditions. See the enum above for a
 * description of each. */
// @{
extern int halide_error_explicit_bounds_too_small(void *user_context, const char *func_name, const char *var_name,
                                                      int min_bound, int max_bound, int min_required, int max_required);
extern int halide_error_bad_type(void *user_context, const char *func_name,
                                 uint32_t type_given, uint32_t correct_type); // N.B. The last two args are the bit representation of a halide_type_t
extern int halide_error_bad_dimensions(void *user_context, const char *func_name,
                                       int32_t dimensions_given, int32_t correct_dimensions);
extern int halide_error_access_out_of_bounds(void *user_context, const char *func_name,
                                             int dimension, int min_touched, int max_touched,
                                             int min_valid, int max_valid);
extern int halide_error_buffer_allocation_too_large(void *user_context, const char *buffer_name,
                                                    uint64_t allocation_size, uint64_t max_size);
extern int halide_error_buffer_extents_negative(void *user_context, const char *buffer_name, int dimension, int extent);
extern int halide_error_buffer_extents_too_large(void *user_context, const char *buffer_name,
                                                 int64_t actual_size, int64_t max_size);
extern int halide_error_constraints_make_required_region_smaller(void *user_context, const char *buffer_name,
                                                                 int dimension,
                                                                 int constrained_min, int constrained_extent,
                                                                 int required_min, int required_extent);
extern int halide_error_constraint_violated(void *user_context, const char *var, int val,
                                            const char *constrained_var, int constrained_val);
extern int halide_error_param_too_small_i64(void *user_context, const char *param_name,
                                            int64_t val, int64_t min_val);
extern int halide_error_param_too_small_u64(void *user_context, const char *param_name,
                                            uint64_t val, uint64_t min_val);
extern int halide_error_param_too_small_f64(void *user_context, const char *param_name,
                                            double val, double min_val);
extern int halide_error_param_too_large_i64(void *user_context, const char *param_name,
                                            int64_t val, int64_t max_val);
extern int halide_error_param_too_large_u64(void *user_context, const char *param_name,
                                            uint64_t val, uint64_t max_val);
extern int halide_error_param_too_large_f64(void *user_context, const char *param_name,
                                            double val, double max_val);
extern int halide_error_out_of_memory(void *user_context);
extern int halide_error_buffer_argument_is_null(void *user_context, const char *buffer_name);
extern int halide_error_debug_to_file_failed(void *user_context, const char *func,
                                             const char *filename, int error_code);
extern int halide_error_unaligned_host_ptr(void *user_context, const char *func_name, int alignment);
extern int halide_error_host_is_null(void *user_context, const char *func_name);
extern int halide_error_failed_to_upgrade_buffer_t(void *user_context,
                                                   const char *input_name,
                                                   const char *reason);
extern int halide_error_failed_to_downgrade_buffer_t(void *user_context,
                                                     const char *input_name,
                                                     const char *reason);
extern int halide_error_bad_fold(void *user_context, const char *func_name, const char *var_name,
                                 const char *loop_name);
extern int halide_error_bad_extern_fold(void *user_context, const char *func_name,
                                        int dim, int min, int extent, int valid_min, int fold_factor);

extern int halide_error_fold_factor_too_small(void *user_context, const char *func_name, const char *var_name,
                                              int fold_factor, const char *loop_name, int required_extent);
extern int halide_error_requirement_failed(void *user_context, const char *condition, const char *message);
extern int halide_error_specialize_fail(void *user_context, const char *message);
extern int halide_error_no_device_interface(void *user_context);
extern int halide_error_device_interface_no_device(void *user_context);
extern int halide_error_host_and_device_dirty(void *user_context);
extern int halide_error_buffer_is_null(void *user_context, const char *routine);
extern int halide_error_integer_division_by_zero(void *user_context);
// @}

/** Optional features a compilation Target can have.
 */
typedef enum halide_target_feature_t {
    halide_target_feature_jit = 0,  ///< Generate code that will run immediately inside the calling process.
    halide_target_feature_debug = 1,  ///< Turn on debug info and output for runtime code.
    halide_target_feature_no_asserts = 2,  ///< Disable all runtime checks, for slightly tighter code.
    halide_target_feature_no_bounds_query = 3, ///< Disable the bounds querying functionality.

    halide_target_feature_sse41 = 4,  ///< Use SSE 4.1 and earlier instructions. Only relevant on x86.
    halide_target_feature_avx = 5,  ///< Use AVX 1 instructions. Only relevant on x86.
    halide_target_feature_avx2 = 6,  ///< Use AVX 2 instructions. Only relevant on x86.
    halide_target_feature_fma = 7,  ///< Enable x86 FMA instruction
    halide_target_feature_fma4 = 8,  ///< Enable x86 (AMD) FMA4 instruction set
    halide_target_feature_f16c = 9,  ///< Enable x86 16-bit float support

    halide_target_feature_armv7s = 10,  ///< Generate code for ARMv7s. Only relevant for 32-bit ARM.
    halide_target_feature_no_neon = 11,  ///< Avoid using NEON instructions. Only relevant for 32-bit ARM.

    halide_target_feature_vsx = 12,  ///< Use VSX instructions. Only relevant on POWERPC.
    halide_target_feature_power_arch_2_07 = 13,  ///< Use POWER ISA 2.07 new instructions. Only relevant on POWERPC.

    halide_target_feature_cuda = 14,  ///< Enable the CUDA runtime. Defaults to compute capability 2.0 (Fermi)
    halide_target_feature_cuda_capability30 = 15,  ///< Enable CUDA compute capability 3.0 (Kepler)
    halide_target_feature_cuda_capability32 = 16,  ///< Enable CUDA compute capability 3.2 (Tegra K1)
    halide_target_feature_cuda_capability35 = 17,  ///< Enable CUDA compute capability 3.5 (Kepler)
    halide_target_feature_cuda_capability50 = 18,  ///< Enable CUDA compute capability 5.0 (Maxwell)

    halide_target_feature_opencl = 19,  ///< Enable the OpenCL runtime.
    halide_target_feature_cl_doubles = 20,  ///< Enable double support on OpenCL targets

    halide_target_feature_opengl = 21,  ///< Enable the OpenGL runtime.
    halide_target_feature_openglcompute = 22, ///< Enable OpenGL Compute runtime.

    halide_target_feature_unused_23 = 23, ///< Unused. (Formerly: Enable the RenderScript runtime.)

    halide_target_feature_user_context = 24,  ///< Generated code takes a user_context pointer as first argument

    halide_target_feature_matlab = 25,  ///< Generate a mexFunction compatible with Matlab mex libraries. See tools/mex_halide.m.

    halide_target_feature_profile = 26, ///< Launch a sampling profiler alongside the Halide pipeline that monitors and reports the runtime used by each Func
    halide_target_feature_no_runtime = 27, ///< Do not include a copy of the Halide runtime in any generated object file or assembly

    halide_target_feature_metal = 28, ///< Enable the (Apple) Metal runtime.
    halide_target_feature_mingw = 29, ///< For Windows compile to MinGW toolset rather then Visual Studio

    halide_target_feature_c_plus_plus_mangling = 30, ///< Generate C++ mangled names for result function, et al

    halide_target_feature_large_buffers = 31, ///< Enable 64-bit buffer indexing to support buffers > 2GB. Ignored if bits != 64.

    halide_target_feature_hvx_64 = 32, ///< Enable HVX 64 byte mode.
    halide_target_feature_hvx_128 = 33, ///< Enable HVX 128 byte mode.
    halide_target_feature_hvx_v62 = 34, ///< Enable Hexagon v62 architecture.
    halide_target_feature_fuzz_float_stores = 35, ///< On every floating point store, set the last bit of the mantissa to zero. Pipelines for which the output is very different with this feature enabled may also produce very different output on different processors.
    halide_target_feature_soft_float_abi = 36, ///< Enable soft float ABI. This only enables the soft float ABI calling convention, which does not necessarily use soft floats.
    halide_target_feature_msan = 37, ///< Enable hooks for MSAN support.
    halide_target_feature_avx512 = 38, ///< Enable the base AVX512 subset supported by all AVX512 architectures. The specific feature sets are AVX-512F and AVX512-CD. See https://en.wikipedia.org/wiki/AVX-512 for a description of each AVX subset.
    halide_target_feature_avx512_knl = 39, ///< Enable the AVX512 features supported by Knight's Landing chips, such as the Xeon Phi x200. This includes the base AVX512 set, and also AVX512-CD and AVX512-ER.
    halide_target_feature_avx512_skylake = 40, ///< Enable the AVX512 features supported by Skylake Xeon server processors. This adds AVX512-VL, AVX512-BW, and AVX512-DQ to the base set. The main difference from the base AVX512 set is better support for small integer ops. Note that this does not include the Knight's Landing features. Note also that these features are not available on Skylake desktop and mobile processors.
    halide_target_feature_avx512_cannonlake = 41, ///< Enable the AVX512 features expected to be supported by future Cannonlake processors. This includes all of the Skylake features, plus AVX512-IFMA and AVX512-VBMI.
    halide_target_feature_hvx_use_shared_object = 42, ///< Deprecated
    halide_target_feature_trace_loads = 43, ///< Trace all loads done by the pipeline. Equivalent to calling Func::trace_loads on every non-inlined Func.
    halide_target_feature_trace_stores = 44, ///< Trace all stores done by the pipeline. Equivalent to calling Func::trace_stores on every non-inlined Func.
    halide_target_feature_trace_realizations = 45, ///< Trace all realizations done by the pipeline. Equivalent to calling Func::trace_realizations on every non-inlined Func.
    halide_target_feature_cuda_capability61 = 46,  ///< Enable CUDA compute capability 6.1 (Pascal)
    halide_target_feature_hvx_v65 = 47, ///< Enable Hexagon v65 architecture.
    halide_target_feature_hvx_v66 = 48, ///< Enable Hexagon v66 architecture.
    halide_target_feature_cl_half = 49,  ///< Enable half support on OpenCL targets
    halide_target_feature_strict_float = 50, ///< Turn off all non-IEEE floating-point optimization. Currently applies only to LLVM targets.
    halide_target_feature_legacy_buffer_wrappers = 51,  ///< Emit legacy wrapper code for buffer_t (vs halide_buffer_t) when AOT-compiled.
    halide_target_feature_tsan = 52, ///< Enable hooks for TSAN support.
    halide_target_feature_asan = 53, ///< Enable hooks for ASAN support.
    halide_target_feature_d3d12compute = 54, ///< Enable Direct3D 12 Compute runtime.
    halide_target_feature_check_unsafe_promises = 55, ///< Insert assertions for promises.
    halide_target_feature_hexagon_dma = 56, ///< Enable Hexagon DMA buffers.
    halide_target_feature_embed_bitcode = 57,  ///< Emulate clang -fembed-bitcode flag.
    halide_target_feature_disable_llvm_loop_vectorize = 58,  ///< Disable loop vectorization in LLVM. (Ignored for non-LLVM targets.)
    halide_target_feature_disable_llvm_loop_unroll = 59,  ///< Disable loop unrolling in LLVM. (Ignored for non-LLVM targets.)
    halide_target_feature_coreir = 60, ///< Enable output to CoreIR.
    halide_target_feature_coreir_valid = 61, ///< Enable output signal valid for CoreIR.
    halide_target_feature_hls = 62, ///< Enable output to HLS.
    halide_target_feature_coreir_hls = 63, ///< Enable output to CoreIRHLS
    halide_target_feature_clockwork = 64, ///< Enable output to Clockwork
    halide_target_feature_use_extract_hw_kernel = 65, ///< Enable old hwkernel functionality instead of unified buffer
    halide_target_feature_bfloat_hardware = 66, ///< Enable use of bfloat hardware in hardware accelerators as oppoosed to float
    halide_target_feature_enable_ponds = 67, ///< Enable Clockwork to map memories to ponds  in hardware accelerators in addition to memory tiles
    halide_target_feature_end = 68 ///< A sentinel. Every target is considered to have this feature, and setting this feature does nothing.
} halide_target_feature_t;

/** This function is called internally by Halide in some situations to determine
 * if the current execution environment can support the given set of
 * halide_target_feature_t flags. The implementation must do the following:
 *
 * -- If there are flags set in features that the function knows *cannot* be supported, return 0.
 * -- Otherwise, return 1.
 * -- Note that any flags set in features that the function doesn't know how to test should be ignored;
 * this implies that a return value of 1 means "not known to be bad" rather than "known to be good".
 *
 * In other words: a return value of 0 means "It is not safe to use code compiled with these features",
 * while a return value of 1 means "It is not obviously unsafe to use code compiled with these features".
 *
 * The default implementation simply calls halide_default_can_use_target_features.
 *
 * Note that `features` points to an array of `count` uint64_t; this array must contain enough
 * bits to represent all the currently known features. Any excess bits must be set to zero.
 */
// @{
extern int halide_can_use_target_features(int count, const uint64_t *features);
typedef int (*halide_can_use_target_features_t)(int count, const uint64_t *features);
extern halide_can_use_target_features_t halide_set_custom_can_use_target_features(halide_can_use_target_features_t);
// @}

/**
 * This is the default implementation of halide_can_use_target_features; it is provided
 * for convenience of user code that may wish to extend halide_can_use_target_features
 * but continue providing existing support, e.g.
 *
 *     int halide_can_use_target_features(int count, const uint64_t *features) {
 *          if (features[halide_target_somefeature >> 6] & (1LL << (halide_target_somefeature & 63))) {
 *              if (!can_use_somefeature()) {
 *                  return 0;
 *              }
 *          }
 *          return halide_default_can_use_target_features(count, features);
 *     }
 */
extern int halide_default_can_use_target_features(int count, const uint64_t *features);


typedef struct halide_dimension_t {
    int32_t min, extent, stride;

    // Per-dimension flags. None are defined yet (This is reserved for future use).
    uint32_t flags;

#ifdef __cplusplus
    HALIDE_ALWAYS_INLINE halide_dimension_t() : min(0), extent(0), stride(0), flags(0) {}
    HALIDE_ALWAYS_INLINE halide_dimension_t(int32_t m, int32_t e, int32_t s, uint32_t f = 0) :
        min(m), extent(e), stride(s), flags(f) {}

    HALIDE_ALWAYS_INLINE bool operator==(const halide_dimension_t &other) const {
        return (min == other.min) &&
            (extent == other.extent) &&
            (stride == other.stride) &&
            (flags == other.flags);
    }

    HALIDE_ALWAYS_INLINE bool operator!=(const halide_dimension_t &other) const {
        return !(*this == other);
    }
#endif
} halide_dimension_t;

#ifdef __cplusplus
} // extern "C"
#endif

typedef enum {halide_buffer_flag_host_dirty = 1,
              halide_buffer_flag_device_dirty = 2} halide_buffer_flags;

/**
 * The raw representation of an image passed around by generated
 * Halide code. It includes some stuff to track whether the image is
 * not actually in main memory, but instead on a device (like a
 * GPU). For a more convenient C++ wrapper, use Halide::Buffer<T>. */
typedef struct halide_buffer_t {
    /** A device-handle for e.g. GPU memory used to back this buffer. */
    uint64_t device;

    /** The interface used to interpret the above handle. */
    const struct halide_device_interface_t *device_interface;

    /** A pointer to the start of the data in main memory. In terms of
     * the Halide coordinate system, this is the address of the min
     * coordinates (defined below). */
    uint8_t* host;

    /** flags with various meanings. */
    uint64_t flags;

    /** The type of each buffer element. */
    struct halide_type_t type;

    /** The dimensionality of the buffer. */
    int32_t dimensions;

    /** The shape of the buffer. Halide does not own this array - you
     * must manage the memory for it yourself. */
    halide_dimension_t *dim;

    /** Pads the buffer up to a multiple of 8 bytes */
    void *padding;

#ifdef __cplusplus
    /** Convenience methods for accessing the flags */
    // @{
    HALIDE_ALWAYS_INLINE bool get_flag(halide_buffer_flags flag) const {
        return (flags & flag) != 0;
    }

    HALIDE_ALWAYS_INLINE void set_flag(halide_buffer_flags flag, bool value) {
        if (value) {
            flags |= flag;
        } else {
            flags &= ~flag;
        }
    }

    HALIDE_ALWAYS_INLINE bool host_dirty() const {
        return get_flag(halide_buffer_flag_host_dirty);
    }

    HALIDE_ALWAYS_INLINE bool device_dirty() const {
        return get_flag(halide_buffer_flag_device_dirty);
    }

    HALIDE_ALWAYS_INLINE void set_host_dirty(bool v = true) {
        set_flag(halide_buffer_flag_host_dirty, v);
    }

    HALIDE_ALWAYS_INLINE void set_device_dirty(bool v = true) {
        set_flag(halide_buffer_flag_device_dirty, v);
    }
    // @}

    /** The total number of elements this buffer represents. Equal to
     * the product of the extents */
    HALIDE_ALWAYS_INLINE size_t number_of_elements() const {
        size_t s = 1;
        for (int i = 0; i < dimensions; i++) {
            s *= dim[i].extent;
        }
        return s;
    }

    /** A pointer to the element with the lowest address. If all
     * strides are positive, equal to the host pointer. */
    HALIDE_ALWAYS_INLINE uint8_t *begin() const {
        ptrdiff_t index = 0;
        for (int i = 0; i < dimensions; i++) {
            if (dim[i].stride < 0) {
                index += dim[i].stride * (dim[i].extent - 1);
            }
        }
        return host + index * type.bytes();
    }

    /** A pointer to one beyond the element with the highest address. */
    HALIDE_ALWAYS_INLINE uint8_t *end() const {
        ptrdiff_t index = 0;
        for (int i = 0; i < dimensions; i++) {
            if (dim[i].stride > 0) {
                index += dim[i].stride * (dim[i].extent - 1);
            }
        }
        index += 1;
        return host + index * type.bytes();
    }

    /** The total number of bytes spanned by the data in memory. */
    HALIDE_ALWAYS_INLINE size_t size_in_bytes() const {
        return (size_t)(end() - begin());
    }

    /** A pointer to the element at the given location. */
    HALIDE_ALWAYS_INLINE uint8_t *address_of(const int *pos) const {
        ptrdiff_t index = 0;
        for (int i = 0; i < dimensions; i++) {
            index += dim[i].stride * (pos[i] - dim[i].min);
        }
        return host + index * type.bytes();
    }

    /** Attempt to call device_sync for the buffer. If the buffer
     * has no device_interface (or no device_sync), this is a quiet no-op.
     * Calling this explicitly should rarely be necessary, except for profiling. */
    HALIDE_ALWAYS_INLINE int device_sync(void *ctx = NULL) {
        if (device_interface && device_interface->device_sync) {
            return device_interface->device_sync(ctx, this);
        }
        return 0;
    }

    /** Check if an input buffer passed extern stage is a querying
     * bounds. Compared to doing the host pointer check directly,
     * this both adds clarity to code and will facilitate moving to
     * another representation for bounds query arguments. */
    HALIDE_ALWAYS_INLINE bool is_bounds_query() const {
        return host == NULL && device == 0;
    }

#endif
} halide_buffer_t;

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HALIDE_ATTRIBUTE_DEPRECATED
#ifdef HALIDE_ALLOW_DEPRECATED
#define HALIDE_ATTRIBUTE_DEPRECATED(x)
#else
#ifdef _MSC_VER
#define HALIDE_ATTRIBUTE_DEPRECATED(x) __declspec(deprecated(x))
#else
#define HALIDE_ATTRIBUTE_DEPRECATED(x) __attribute__((deprecated(x)))
#endif
#endif
#endif

/** The old buffer_t, included for compatibility with old code. Don't
 * use it. */
#ifndef BUFFER_T_DEFINED
#define BUFFER_T_DEFINED
typedef struct buffer_t {
    uint64_t dev;
    uint8_t* host;
    int32_t extent[4];
    int32_t stride[4];
    int32_t min[4];
    int32_t elem_size;
    HALIDE_ATTRIBUTE_ALIGN(1) bool host_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) bool dev_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t _padding[10 - sizeof(void *)];
} buffer_t;
#endif // BUFFER_T_DEFINED

/** Copies host pointer, mins, extents, strides, and device state from
 * an old-style buffer_t into a new-style halide_buffer_t. If bounds_query_only is nonzero,
 * the copy is only done if the old_buf has null host and dev (ie, a bounds query is being
 * performed); otherwise new_buf is left untouched. (This is used for input buffers to avoid
 * benign data races.) The dimensions and type fields of the new buffer_t should already be
 * set. Returns an error code if the upgrade could not be performed. */
extern int halide_upgrade_buffer_t(void *user_context, const char *name,
                                   const buffer_t *old_buf, halide_buffer_t *new_buf,
                                   int bounds_query_only);

/** Copies the host pointer, mins, extents, strides, and device state
 * from a halide_buffer_t to a buffer_t. Also sets elem_size. Useful
 * for backporting the results of bounds inference. */
extern int halide_downgrade_buffer_t(void *user_context, const char *name,
                                     const halide_buffer_t *new_buf, buffer_t *old_buf);

/** Copies the dirty flags and device allocation state from a new
 * buffer_t back to a legacy buffer_t. */
extern int halide_downgrade_buffer_t_device_fields(void *user_context, const char *name,
                                                   const halide_buffer_t *new_buf, buffer_t *old_buf);

/** halide_scalar_value_t is a simple union able to represent all the well-known
 * scalar values in a filter argument. Note that it isn't tagged with a type;
 * you must ensure you know the proper type before accessing. Most user
 * code will never need to create instances of this struct; its primary use
 * is to hold def/min/max values in a halide_filter_argument_t. (Note that
 * this is conceptually just a union; it's wrapped in a struct to ensure
 * that it doesn't get anonymized by LLVM.)
 */
struct halide_scalar_value_t {
    union {
        bool b;
        int8_t i8;
        int16_t i16;
        int32_t i32;
        int64_t i64;
        uint8_t u8;
        uint16_t u16;
        uint32_t u32;
        uint64_t u64;
        float f32;
        double f64;
        void *handle;
    } u;
    #ifdef __cplusplus
    HALIDE_ALWAYS_INLINE halide_scalar_value_t() {u.u64 = 0;}
    #endif
};

enum halide_argument_kind_t {
    halide_argument_kind_input_scalar = 0,
    halide_argument_kind_input_buffer = 1,
    halide_argument_kind_output_buffer = 2
};

/*
    These structs must be robust across different compilers and settings; when
    modifying them, strive for the following rules:

    1) All fields are explicitly sized. I.e. must use int32_t and not "int"
    2) All fields must land on an alignment boundary that is the same as their size
    3) Explicit padding is added to make that so
    4) The sizeof the struct is padded out to a multiple of the largest natural size thing in the struct
    5) don't forget that 32 and 64 bit pointers are different sizes
*/

/**
 * Obsolete version of halide_filter_argument_t; only present in
 * code that wrote halide_filter_metadata_t version 0.
 */
struct halide_filter_argument_t_v0 {
    const char *name;
    int32_t kind;
    int32_t dimensions;
    struct halide_type_t type;
    const struct halide_scalar_value_t *def, *min, *max;
};

/**
 * halide_filter_argument_t is essentially a plain-C-struct equivalent to
 * Halide::Argument; most user code will never need to create one.
 */
struct halide_filter_argument_t {
    const char *name;       // name of the argument; will never be null or empty.
    int32_t kind;           // actually halide_argument_kind_t
    int32_t dimensions;     // always zero for scalar arguments
    struct halide_type_t type;
    // These pointers should always be null for buffer arguments,
    // and *may* be null for scalar arguments. (A null value means
    // there is no def/min/max/estimate specified for this argument.)
    const struct halide_scalar_value_t *scalar_def, *scalar_min, *scalar_max, *scalar_estimate;
    // This pointer should always be null for scalar arguments,
    // and *may* be null for buffer arguments. If not null, it should always
    // point to an array of dimensions*2 pointers, which will be the (min, extent)
    // estimates for each dimension of the buffer. (Note that any of the pointers
    // may be null as well.)
    int64_t const* const* buffer_estimates;
};

struct halide_filter_metadata_t {
#ifdef __cplusplus
    static const int32_t VERSION = 1;
#endif

    /** version of this metadata; currently always 1. */
    int32_t version;

    /** The number of entries in the arguments field. This is always >= 1. */
    int32_t num_arguments;

    /** An array of the filters input and output arguments; this will never be
     * null. The order of arguments is not guaranteed (input and output arguments
     * may come in any order); however, it is guaranteed that all arguments
     * will have a unique name within a given filter. */
    const struct halide_filter_argument_t* arguments;

    /** The Target for which the filter was compiled. This is always
     * a canonical Target string (ie a product of Target::to_string). */
    const char* target;

    /** The function name of the filter. */
    const char* name;
};

/** halide_register_argv_and_metadata() is a **user-defined** function that
 * must be provided in order to use the registration.cc files produced
 * by Generators when the 'registration' output is requested. Each registration.cc
 * file provides a static initializer that calls this function with the given
 * filter's argv-call variant, its metadata, and (optionally) and additional
 * textual data that the build system chooses to tack on for its own purposes.
 * Note that this will be called at static-initializer time (i.e., before
 * main() is called), and in an unpredictable order. Note that extra_key_value_pairs
 * may be nullptr; if it's not null, it's expected to be a null-terminated list
 * of strings, with an even number of entries. */
void halide_register_argv_and_metadata(
    int (*filter_argv_call)(void **),
    const struct halide_filter_metadata_t *filter_metadata,
    const char * const *extra_key_value_pairs
);

/** The functions below here are relevant for pipelines compiled with
 * the -profile target flag, which runs a sampling profiler thread
 * alongside the pipeline. */

/** Per-Func state tracked by the sampling profiler. */
struct halide_profiler_func_stats {
    /** Total time taken evaluating this Func (in nanoseconds). */
    uint64_t time;

    /** The current memory allocation of this Func. */
    uint64_t memory_current;

    /** The peak memory allocation of this Func. */
    uint64_t memory_peak;

    /** The total memory allocation of this Func. */
    uint64_t memory_total;

    /** The peak stack allocation of this Func's threads. */
    uint64_t stack_peak;

    /** The average number of thread pool worker threads active while computing this Func. */
    uint64_t active_threads_numerator, active_threads_denominator;

    /** The name of this Func. A global constant string. */
    const char *name;

    /** The total number of memory allocation of this Func. */
    int num_allocs;
};

/** Per-pipeline state tracked by the sampling profiler. These exist
 * in a linked list. */
struct halide_profiler_pipeline_stats {
    /** Total time spent inside this pipeline (in nanoseconds) */
    uint64_t time;

    /** The current memory allocation of funcs in this pipeline. */
    uint64_t memory_current;

    /** The peak memory allocation of funcs in this pipeline. */
    uint64_t memory_peak;

    /** The total memory allocation of funcs in this pipeline. */
    uint64_t memory_total;

    /** The average number of thread pool worker threads doing useful
     * work while computing this pipeline. */
    uint64_t active_threads_numerator, active_threads_denominator;

    /** The name of this pipeline. A global constant string. */
    const char *name;

    /** An array containing states for each Func in this pipeline. */
    struct halide_profiler_func_stats *funcs;

    /** The next pipeline_stats pointer. It's a void * because types
     * in the Halide runtime may not currently be recursive. */
    void *next;

    /** The number of funcs in this pipeline. */
    int num_funcs;

    /** An internal base id used to identify the funcs in this pipeline. */
    int first_func_id;

    /** The number of times this pipeline has been run. */
    int runs;

    /** The total number of samples taken inside of this pipeline. */
    int samples;

    /** The total number of memory allocation of funcs in this pipeline. */
    int num_allocs;
};

/** The global state of the profiler. */

struct halide_profiler_state {
    /** Guards access to the fields below. If not locked, the sampling
     * profiler thread is free to modify things below (including
     * reordering the linked list of pipeline stats). */
    struct halide_mutex lock;

    /** The amount of time the profiler thread sleeps between samples
     * in milliseconds. Defaults to 1 */
    int sleep_time;

    /** An internal id used for bookkeeping. */
    int first_free_id;

    /** The id of the current running Func. Set by the pipeline, read
     * periodically by the profiler thread. */
    int current_func;

    /** The number of threads currently doing work. */
    int active_threads;

    /** A linked list of stats gathered for each pipeline. */
    struct halide_profiler_pipeline_stats *pipelines;

    /** Retrieve remote profiler state. Used so that the sampling
     * profiler can follow along with execution that occurs elsewhere,
     * e.g. on a DSP. If null, it reads from the int above instead. */
    void (*get_remote_profiler_state)(int *func, int *active_workers);

    /** Sampling thread reference to be joined at shutdown. */
    struct halide_thread *sampling_thread;
};

/** Profiler func ids with special meanings. */
enum {
    /// current_func takes on this value when not inside Halide code
    halide_profiler_outside_of_halide = -1,
    /// Set current_func to this value to tell the profiling thread to
    /// halt. It will start up again next time you run a pipeline with
    /// profiling enabled.
    halide_profiler_please_stop = -2
};

/** Get a pointer to the global profiler state for programmatic
 * inspection. Lock it before using to pause the profiler. */
extern struct halide_profiler_state *halide_profiler_get_state();

/** Get a pointer to the pipeline state associated with pipeline_name.
 * This function grabs the global profiler state's lock on entry. */
extern struct halide_profiler_pipeline_stats *halide_profiler_get_pipeline_state(const char *pipeline_name);

/** Reset profiler state cheaply. May leave threads running or some
 * memory allocated but all accumluated statistics are reset.
 * WARNING: Do NOT call this method while any halide pipeline is
 * running; halide_profiler_memory_allocate/free and
 * halide_profiler_stack_peak_update update the profiler pipeline's
 * state without grabbing the global profiler state's lock. */
extern void halide_profiler_reset();

/** Reset all profiler state.
 * WARNING: Do NOT call this method while any halide pipeline is
 * running; halide_profiler_memory_allocate/free and
 * halide_profiler_stack_peak_update update the profiler pipeline's
 * state without grabbing the global profiler state's lock. */
void halide_profiler_shutdown();

/** Print out timing statistics for everything run since the last
 * reset. Also happens at process exit. */
extern void halide_profiler_report(void *user_context);

/// \name "Float16" functions
/// These functions operate of bits (``uint16_t``) representing a half
/// precision floating point number (IEEE-754 2008 binary16).
//{@

/** Read bits representing a half precision floating point number and return
 *  the float that represents the same value */
extern float halide_float16_bits_to_float(uint16_t);

/** Read bits representing a half precision floating point number and return
 *  the double that represents the same value */
extern double halide_float16_bits_to_double(uint16_t);

// TODO: Conversion functions to half

//@}

#ifdef __cplusplus
} // End extern "C"
#endif

#ifdef __cplusplus

namespace {
template<typename T> struct check_is_pointer;
template<typename T> struct check_is_pointer<T *> {};
}

/** Construct the halide equivalent of a C type */
template<typename T>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of() {
    // Create a compile-time error if T is not a pointer (without
    // using any includes - this code goes into the runtime).
    check_is_pointer<T> check;
    (void)check;
    return halide_type_t(halide_type_handle, 64);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<float>() {
    return halide_type_t(halide_type_float, 32);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<double>() {
    return halide_type_t(halide_type_float, 64);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<bool>() {
    return halide_type_t(halide_type_uint, 1);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<uint8_t>() {
    return halide_type_t(halide_type_uint, 8);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<uint16_t>() {
    return halide_type_t(halide_type_uint, 16);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<uint32_t>() {
    return halide_type_t(halide_type_uint, 32);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<uint64_t>() {
    return halide_type_t(halide_type_uint, 64);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<int8_t>() {
    return halide_type_t(halide_type_int, 8);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<int16_t>() {
    return halide_type_t(halide_type_int, 16);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<int32_t>() {
    return halide_type_t(halide_type_int, 32);
}

template<>
HALIDE_ALWAYS_INLINE halide_type_t halide_type_of<int64_t>() {
    return halide_type_t(halide_type_int, 64);
}

#endif

#endif // HALIDE_HALIDERUNTIME_H

#ifdef COMPILING_HALIDE_RUNTIME
#include "HalideRuntime.h"
#define HALIDE_BUFFER_HELPER_ATTRS __attribute__((always_inline, weak))
#else
#define HALIDE_BUFFER_HELPER_ATTRS inline
#endif

// Structs are annoying to deal with from within Halide Stmts. These
// utility functions are for dealing with buffer_t in that
// context. They are not intended for use outside of Halide code, and
// not exposed in HalideRuntime.h. The symbols are private to the
// module and should be inlined and then stripped. This blob of code
// also gets copy-pasted into C outputs.

extern "C" {

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_get_dimensions(const halide_buffer_t *buf) {
    return buf->dimensions;
}

HALIDE_BUFFER_HELPER_ATTRS
uint8_t *_halide_buffer_get_host(const halide_buffer_t *buf) {
    return buf->host;
}

HALIDE_BUFFER_HELPER_ATTRS
uint64_t _halide_buffer_get_device(const halide_buffer_t *buf) {
    return buf->device;
}

HALIDE_BUFFER_HELPER_ATTRS
const struct halide_device_interface_t *_halide_buffer_get_device_interface(const halide_buffer_t *buf) {
    return buf->device_interface;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_get_min(const halide_buffer_t *buf, int d) {
    return buf->dim[d].min;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_get_max(const halide_buffer_t *buf, int d) {
    return buf->dim[d].min + buf->dim[d].extent - 1;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_get_extent(const halide_buffer_t *buf, int d) {
    return buf->dim[d].extent;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_get_stride(const halide_buffer_t *buf, int d) {
    return buf->dim[d].stride;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_set_host_dirty(halide_buffer_t *buf, bool val) {
    buf->set_host_dirty(val);
    return 0;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_set_device_dirty(halide_buffer_t *buf, bool val) {
    buf->set_device_dirty(val);
    return 0;
}

HALIDE_BUFFER_HELPER_ATTRS
bool _halide_buffer_get_host_dirty(const halide_buffer_t *buf) {
    return buf->host_dirty();
}

HALIDE_BUFFER_HELPER_ATTRS
bool _halide_buffer_get_device_dirty(const halide_buffer_t *buf) {
    return buf->device_dirty();
}

HALIDE_BUFFER_HELPER_ATTRS
halide_dimension_t *_halide_buffer_get_shape(halide_buffer_t *buf) {
    return buf->dim;
}

HALIDE_BUFFER_HELPER_ATTRS
bool _halide_buffer_is_bounds_query(const halide_buffer_t *buf) {
    return buf->host == NULL && buf->device == 0;
}

HALIDE_BUFFER_HELPER_ATTRS
uint32_t _halide_buffer_get_type(const halide_buffer_t *buf) {
    return buf->type.as_u32();
}

HALIDE_BUFFER_HELPER_ATTRS
halide_buffer_t *_halide_buffer_init(halide_buffer_t *dst,
                                     halide_dimension_t *dst_shape,
                                     void *host,
                                     uint64_t device, halide_device_interface_t *device_interface,
                                     int type_code, int type_bits,
                                     int dimensions,
                                     halide_dimension_t *shape,
                                     uint64_t flags) {
    dst->host = (uint8_t *)host;
    dst->device = device;
    dst->device_interface = device_interface;
    dst->type.code = (halide_type_code_t)type_code;
    dst->type.bits = (uint8_t)type_bits;
    dst->type.lanes = 1;
    dst->dimensions = dimensions;
    dst->dim = dst_shape;
    if (shape != dst->dim) {
        for (int i = 0; i < dimensions; i++) {
            dst->dim[i] = shape[i];
        }
    }
    dst->flags = flags;
    return dst;
}

HALIDE_BUFFER_HELPER_ATTRS
halide_buffer_t *_halide_buffer_init_from_buffer(halide_buffer_t *dst,
                                                 halide_dimension_t *dst_shape,
                                                 const halide_buffer_t *src) {
    dst->host = src->host;
    dst->device = src->device;
    dst->device_interface = src->device_interface;
    dst->type = src->type;
    dst->dimensions = src->dimensions;
    dst->dim = dst_shape;
    dst->flags = src->flags;
    for (int i = 0; i < dst->dimensions; i++) {
        dst->dim[i] = src->dim[i];
    }
    return dst;
}

HALIDE_BUFFER_HELPER_ATTRS
halide_buffer_t *_halide_buffer_crop(void *user_context,
                                     halide_buffer_t *dst,
                                     halide_dimension_t *dst_shape,
                                     const halide_buffer_t *src,
                                     const int *min, const int *extent) {
    *dst = *src;
    dst->dim = dst_shape;
    int64_t offset = 0;
    for (int i = 0; i < dst->dimensions; i++) {
        dst->dim[i] = src->dim[i];
        dst->dim[i].min = min[i];
        dst->dim[i].extent = extent[i];
        offset += (min[i] - src->dim[i].min) * src->dim[i].stride;
    }
    if (dst->host) {
        dst->host += offset * src->type.bytes();
    }
    dst->device_interface = 0;
    dst->device = 0;
    if (src->device_interface) {
        src->device_interface->device_crop(user_context, src, dst);
    }
    return dst;
}


// Called on return from an extern stage where the output buffer was a
// crop of some other larger buffer. This happens for extern stages
// with distinct store_at/compute_at levels. Each call to the stage
// only fills in part of the buffer.
HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_retire_crop_after_extern_stage(void *user_context,
                                                   void *obj) {
    halide_buffer_t **buffers = (halide_buffer_t **)obj;
    halide_buffer_t *crop = buffers[0];
    halide_buffer_t *parent = buffers[1];

    if (crop->device) {
        if (!parent->device) {
            // We have been given a device allocation by the extern
            // stage. It only represents the cropped region, so we
            // can't just give it to the parent.
            if (crop->device_dirty()) {
                crop->device_interface->copy_to_host(user_context, crop);
            }
            crop->device_interface->device_free(user_context, crop);
        } else {
            // We are a crop of an existing device allocation.
            if (crop->device_dirty()) {
                parent->set_device_dirty();
            }
            crop->device_interface->device_release_crop(user_context, crop);
        }
    }
    if (crop->host_dirty()) {
        parent->set_host_dirty();
    }
    return 0;
}

HALIDE_BUFFER_HELPER_ATTRS
int _halide_buffer_retire_crops_after_extern_stage(void *user_context,
                                                    void *obj) {
    halide_buffer_t **buffers = (halide_buffer_t **)obj;
    while (*buffers) {
        _halide_buffer_retire_crop_after_extern_stage(user_context, buffers);
        buffers += 2;
    }
    return 0;
}

HALIDE_BUFFER_HELPER_ATTRS
halide_buffer_t *_halide_buffer_set_bounds(halide_buffer_t *buf,
                                           int dim, int min, int extent) {
    buf->dim[dim].min = min;
    buf->dim[dim].extent = extent;
    return buf;
}

}

#undef HALIDE_BUFFER_HELPER_ATTRS

#ifndef HALIDE_FUNCTION_ATTRS
#define HALIDE_FUNCTION_ATTRS
#endif
#include "rdai_api.h"


int resnet_block_clockwork(struct halide_buffer_t *_input_buffer, struct halide_buffer_t *_kernel_buffer, struct halide_buffer_t *_kernel2_buffer, struct halide_buffer_t *_output_buffer) HALIDE_FUNCTION_ATTRS {
 void * const _ucon = nullptr;
 uint64_t _0 = (uint64_t)(_output_buffer);
 uint64_t _1 = (uint64_t)(0);
 bool _2 = _0 != _1;
 if (!_2)  {
  int32_t _3 = halide_error_buffer_argument_is_null(_ucon, "output");
  return _3;
 }
 uint64_t _4 = (uint64_t)(_kernel2_buffer);
 uint64_t _5 = (uint64_t)(0);
 bool _6 = _4 != _5;
 if (!_6)  {
  int32_t _7 = halide_error_buffer_argument_is_null(_ucon, "kernel2");
  return _7;
 }
 uint64_t _8 = (uint64_t)(_kernel_buffer);
 uint64_t _9 = (uint64_t)(0);
 bool _10 = _8 != _9;
 if (!_10)  {
  int32_t _11 = halide_error_buffer_argument_is_null(_ucon, "kernel");
  return _11;
 }
 uint64_t _12 = (uint64_t)(_input_buffer);
 uint64_t _13 = (uint64_t)(0);
 bool _14 = _12 != _13;
 if (!_14)  {
  int32_t _15 = halide_error_buffer_argument_is_null(_ucon, "input");
  return _15;
 }
 bool _16 = _halide_buffer_is_bounds_query(_input_buffer);
 if (_16)
 {
  struct halide_dimension_t *_17 = _halide_buffer_get_shape(_input_buffer);
  uint64_t _18 = (uint64_t)(0);
  void *_19 = (void *)(_18);
  struct halide_device_interface_t *_20 = (struct halide_device_interface_t *)(_18);
  struct {
   const int32_t f_0;
   const int32_t f_1;
   const int32_t f_2;
   const int32_t f_3;
   const int32_t f_4;
   const int32_t f_5;
   const int32_t f_6;
   const int32_t f_7;
   const int32_t f_8;
   const int32_t f_9;
   const int32_t f_10;
   const int32_t f_11;
  } s0 = {
   0,
   3,
   1,
   0,
   0,
   32,
   3,
   0,
   0,
   32,
   96,
   0
  };
  struct halide_dimension_t *_21 = (struct halide_dimension_t *)(&s0);
  struct halide_buffer_t *_22 = _halide_buffer_init(_input_buffer, _17, _19, _18, _20, 1, 8, 3, _21, _18);
  (void)_22;
 } // if _16
 bool _23 = _halide_buffer_is_bounds_query(_kernel_buffer);
 if (_23)
 {
  struct halide_dimension_t *_24 = _halide_buffer_get_shape(_kernel_buffer);
  uint64_t _25 = (uint64_t)(0);
  void *_26 = (void *)(_25);
  struct halide_device_interface_t *_27 = (struct halide_device_interface_t *)(_25);
  struct {
   const int32_t f_0;
   const int32_t f_1;
   const int32_t f_2;
   const int32_t f_3;
   const int32_t f_4;
   const int32_t f_5;
   const int32_t f_6;
   const int32_t f_7;
   const int32_t f_8;
   const int32_t f_9;
   const int32_t f_10;
   const int32_t f_11;
   const int32_t f_12;
   const int32_t f_13;
   const int32_t f_14;
   const int32_t f_15;
  } s1 = {
   0,
   3,
   1,
   0,
   0,
   3,
   3,
   0,
   0,
   3,
   9,
   0,
   0,
   3,
   27,
   0
  };
  struct halide_dimension_t *_28 = (struct halide_dimension_t *)(&s1);
  struct halide_buffer_t *_29 = _halide_buffer_init(_kernel_buffer, _24, _26, _25, _27, 1, 8, 4, _28, _25);
  (void)_29;
 } // if _23
 bool _30 = _halide_buffer_is_bounds_query(_kernel2_buffer);
 if (_30)
 {
  struct halide_dimension_t *_31 = _halide_buffer_get_shape(_kernel2_buffer);
  uint64_t _32 = (uint64_t)(0);
  void *_33 = (void *)(_32);
  struct halide_device_interface_t *_34 = (struct halide_device_interface_t *)(_32);
  struct {
   const int32_t f_0;
   const int32_t f_1;
   const int32_t f_2;
   const int32_t f_3;
   const int32_t f_4;
   const int32_t f_5;
   const int32_t f_6;
   const int32_t f_7;
   const int32_t f_8;
   const int32_t f_9;
   const int32_t f_10;
   const int32_t f_11;
   const int32_t f_12;
   const int32_t f_13;
   const int32_t f_14;
   const int32_t f_15;
  } s2 = {
   0,
   3,
   1,
   0,
   0,
   3,
   3,
   0,
   0,
   3,
   9,
   0,
   0,
   3,
   27,
   0
  };
  struct halide_dimension_t *_35 = (struct halide_dimension_t *)(&s2);
  struct halide_buffer_t *_36 = _halide_buffer_init(_kernel2_buffer, _31, _33, _32, _34, 1, 8, 4, _35, _32);
  (void)_36;
 } // if _30
 bool _37 = _halide_buffer_is_bounds_query(_output_buffer);
 if (_37)
 {
  struct halide_dimension_t *_38 = _halide_buffer_get_shape(_output_buffer);
  uint64_t _39 = (uint64_t)(0);
  void *_40 = (void *)(_39);
  struct halide_device_interface_t *_41 = (struct halide_device_interface_t *)(_39);
  struct {
   const int32_t f_0;
   const int32_t f_1;
   const int32_t f_2;
   const int32_t f_3;
   const int32_t f_4;
   const int32_t f_5;
   const int32_t f_6;
   const int32_t f_7;
   const int32_t f_8;
   const int32_t f_9;
   const int32_t f_10;
   const int32_t f_11;
  } s3 = {
   0,
   28,
   1,
   0,
   0,
   28,
   28,
   0,
   0,
   3,
   784,
   0
  };
  struct halide_dimension_t *_42 = (struct halide_dimension_t *)(&s3);
  struct halide_buffer_t *_43 = _halide_buffer_init(_output_buffer, _38, _40, _39, _41, 1, 8, 3, _42, _39);
  (void)_43;
 } // if _37
 bool _44 = _halide_buffer_is_bounds_query(_output_buffer);
 bool _45 = _halide_buffer_is_bounds_query(_kernel2_buffer);
 bool _46 = _halide_buffer_is_bounds_query(_input_buffer);
 bool _47 = _halide_buffer_is_bounds_query(_kernel_buffer);
 bool _48 = _46 || _47;
 bool _49 = _45 || _48;
 bool _50 = _44 || _49;
 bool _51 = !(_50);
 if (_51)
 {
  uint32_t _52 = _halide_buffer_get_type(_input_buffer);
  uint32_t _53 = (uint32_t)(67585);
  bool _54 = _52 == _53;
  if (!_54)   {
   uint32_t _55 = _halide_buffer_get_type(_input_buffer);
   uint32_t _56 = (uint32_t)(67585);
   int32_t _57 = halide_error_bad_type(_ucon, "Input buffer input", _55, _56);
   return _57;
  }
  int32_t _58 = _halide_buffer_get_dimensions(_input_buffer);
  bool _59 = _58 == 3;
  if (!_59)   {
   int32_t _60 = _halide_buffer_get_dimensions(_input_buffer);
   int32_t _61 = halide_error_bad_dimensions(_ucon, "Input buffer input", _60, 3);
   return _61;
  }
  uint32_t _62 = _halide_buffer_get_type(_kernel_buffer);
  uint32_t _63 = (uint32_t)(67585);
  bool _64 = _62 == _63;
  if (!_64)   {
   uint32_t _65 = _halide_buffer_get_type(_kernel_buffer);
   uint32_t _66 = (uint32_t)(67585);
   int32_t _67 = halide_error_bad_type(_ucon, "Input buffer kernel", _65, _66);
   return _67;
  }
  int32_t _68 = _halide_buffer_get_dimensions(_kernel_buffer);
  bool _69 = _68 == 4;
  if (!_69)   {
   int32_t _70 = _halide_buffer_get_dimensions(_kernel_buffer);
   int32_t _71 = halide_error_bad_dimensions(_ucon, "Input buffer kernel", _70, 4);
   return _71;
  }
  uint32_t _72 = _halide_buffer_get_type(_kernel2_buffer);
  uint32_t _73 = (uint32_t)(67585);
  bool _74 = _72 == _73;
  if (!_74)   {
   uint32_t _75 = _halide_buffer_get_type(_kernel2_buffer);
   uint32_t _76 = (uint32_t)(67585);
   int32_t _77 = halide_error_bad_type(_ucon, "Input buffer kernel2", _75, _76);
   return _77;
  }
  int32_t _78 = _halide_buffer_get_dimensions(_kernel2_buffer);
  bool _79 = _78 == 4;
  if (!_79)   {
   int32_t _80 = _halide_buffer_get_dimensions(_kernel2_buffer);
   int32_t _81 = halide_error_bad_dimensions(_ucon, "Input buffer kernel2", _80, 4);
   return _81;
  }
  uint32_t _82 = _halide_buffer_get_type(_output_buffer);
  uint32_t _83 = (uint32_t)(67585);
  bool _84 = _82 == _83;
  if (!_84)   {
   uint32_t _85 = _halide_buffer_get_type(_output_buffer);
   uint32_t _86 = (uint32_t)(67585);
   int32_t _87 = halide_error_bad_type(_ucon, "Output buffer output", _85, _86);
   return _87;
  }
  int32_t _88 = _halide_buffer_get_dimensions(_output_buffer);
  bool _89 = _88 == 3;
  if (!_89)   {
   int32_t _90 = _halide_buffer_get_dimensions(_output_buffer);
   int32_t _91 = halide_error_bad_dimensions(_ucon, "Output buffer output", _90, 3);
   return _91;
  }
  int32_t _92 = _halide_buffer_get_min(_input_buffer, 0);
  bool _93 = _92 <= 0;
  int32_t _94 = _halide_buffer_get_extent(_input_buffer, 0);
  int32_t _95 = _94 + _92;
  bool _96 = 3 <= _95;
  bool _97 = _93 && _96;
  if (!_97)   {
   int32_t _98 = _halide_buffer_get_min(_input_buffer, 0);
   int32_t _99 = _halide_buffer_get_extent(_input_buffer, 0);
   int32_t _100 = _99 + _98;
   int32_t _101 = _100 + -1;
   int32_t _102 = halide_error_access_out_of_bounds(_ucon, "Input buffer input", 0, 0, 2, _98, _101);
   return _102;
  }
  int32_t _103 = _halide_buffer_get_extent(_input_buffer, 0);
  bool _104 = 0 <= _103;
  if (!_104)   {
   int32_t _105 = _halide_buffer_get_extent(_input_buffer, 0);
   int32_t _106 = halide_error_buffer_extents_negative(_ucon, "Input buffer input", 0, _105);
   return _106;
  }
  int32_t _107 = _halide_buffer_get_min(_input_buffer, 1);
  bool _108 = _107 <= 0;
  int32_t _109 = _halide_buffer_get_extent(_input_buffer, 1);
  int32_t _110 = _109 + _107;
  bool _111 = 32 <= _110;
  bool _112 = _108 && _111;
  if (!_112)   {
   int32_t _113 = _halide_buffer_get_min(_input_buffer, 1);
   int32_t _114 = _halide_buffer_get_extent(_input_buffer, 1);
   int32_t _115 = _114 + _113;
   int32_t _116 = _115 + -1;
   int32_t _117 = halide_error_access_out_of_bounds(_ucon, "Input buffer input", 1, 0, 31, _113, _116);
   return _117;
  }
  int32_t _118 = _halide_buffer_get_extent(_input_buffer, 1);
  bool _119 = 0 <= _118;
  if (!_119)   {
   int32_t _120 = _halide_buffer_get_extent(_input_buffer, 1);
   int32_t _121 = halide_error_buffer_extents_negative(_ucon, "Input buffer input", 1, _120);
   return _121;
  }
  int32_t _122 = _halide_buffer_get_min(_input_buffer, 2);
  bool _123 = _122 <= 0;
  int32_t _124 = _halide_buffer_get_extent(_input_buffer, 2);
  int32_t _125 = _124 + _122;
  bool _126 = 32 <= _125;
  bool _127 = _123 && _126;
  if (!_127)   {
   int32_t _128 = _halide_buffer_get_min(_input_buffer, 2);
   int32_t _129 = _halide_buffer_get_extent(_input_buffer, 2);
   int32_t _130 = _129 + _128;
   int32_t _131 = _130 + -1;
   int32_t _132 = halide_error_access_out_of_bounds(_ucon, "Input buffer input", 2, 0, 31, _128, _131);
   return _132;
  }
  int32_t _133 = _halide_buffer_get_extent(_input_buffer, 2);
  bool _134 = 0 <= _133;
  if (!_134)   {
   int32_t _135 = _halide_buffer_get_extent(_input_buffer, 2);
   int32_t _136 = halide_error_buffer_extents_negative(_ucon, "Input buffer input", 2, _135);
   return _136;
  }
  int32_t _137 = _halide_buffer_get_min(_kernel_buffer, 0);
  bool _138 = _137 <= 0;
  int32_t _139 = _halide_buffer_get_extent(_kernel_buffer, 0);
  int32_t _140 = _139 + _137;
  bool _141 = 3 <= _140;
  bool _142 = _138 && _141;
  if (!_142)   {
   int32_t _143 = _halide_buffer_get_min(_kernel_buffer, 0);
   int32_t _144 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int32_t _145 = _144 + _143;
   int32_t _146 = _145 + -1;
   int32_t _147 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel", 0, 0, 2, _143, _146);
   return _147;
  }
  int32_t _148 = _halide_buffer_get_extent(_kernel_buffer, 0);
  bool _149 = 0 <= _148;
  if (!_149)   {
   int32_t _150 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int32_t _151 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel", 0, _150);
   return _151;
  }
  int32_t _152 = _halide_buffer_get_min(_kernel_buffer, 1);
  bool _153 = _152 <= 0;
  int32_t _154 = _halide_buffer_get_extent(_kernel_buffer, 1);
  int32_t _155 = _154 + _152;
  bool _156 = 3 <= _155;
  bool _157 = _153 && _156;
  if (!_157)   {
   int32_t _158 = _halide_buffer_get_min(_kernel_buffer, 1);
   int32_t _159 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int32_t _160 = _159 + _158;
   int32_t _161 = _160 + -1;
   int32_t _162 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel", 1, 0, 2, _158, _161);
   return _162;
  }
  int32_t _163 = _halide_buffer_get_extent(_kernel_buffer, 1);
  bool _164 = 0 <= _163;
  if (!_164)   {
   int32_t _165 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int32_t _166 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel", 1, _165);
   return _166;
  }
  int32_t _167 = _halide_buffer_get_min(_kernel_buffer, 2);
  bool _168 = _167 <= 0;
  int32_t _169 = _halide_buffer_get_extent(_kernel_buffer, 2);
  int32_t _170 = _169 + _167;
  bool _171 = 3 <= _170;
  bool _172 = _168 && _171;
  if (!_172)   {
   int32_t _173 = _halide_buffer_get_min(_kernel_buffer, 2);
   int32_t _174 = _halide_buffer_get_extent(_kernel_buffer, 2);
   int32_t _175 = _174 + _173;
   int32_t _176 = _175 + -1;
   int32_t _177 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel", 2, 0, 2, _173, _176);
   return _177;
  }
  int32_t _178 = _halide_buffer_get_extent(_kernel_buffer, 2);
  bool _179 = 0 <= _178;
  if (!_179)   {
   int32_t _180 = _halide_buffer_get_extent(_kernel_buffer, 2);
   int32_t _181 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel", 2, _180);
   return _181;
  }
  int32_t _182 = _halide_buffer_get_min(_kernel_buffer, 3);
  bool _183 = _182 <= 0;
  int32_t _184 = _halide_buffer_get_extent(_kernel_buffer, 3);
  int32_t _185 = _184 + _182;
  bool _186 = 3 <= _185;
  bool _187 = _183 && _186;
  if (!_187)   {
   int32_t _188 = _halide_buffer_get_min(_kernel_buffer, 3);
   int32_t _189 = _halide_buffer_get_extent(_kernel_buffer, 3);
   int32_t _190 = _189 + _188;
   int32_t _191 = _190 + -1;
   int32_t _192 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel", 3, 0, 2, _188, _191);
   return _192;
  }
  int32_t _193 = _halide_buffer_get_extent(_kernel_buffer, 3);
  bool _194 = 0 <= _193;
  if (!_194)   {
   int32_t _195 = _halide_buffer_get_extent(_kernel_buffer, 3);
   int32_t _196 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel", 3, _195);
   return _196;
  }
  int32_t _197 = _halide_buffer_get_min(_kernel2_buffer, 0);
  bool _198 = _197 <= 0;
  int32_t _199 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  int32_t _200 = _199 + _197;
  bool _201 = 3 <= _200;
  bool _202 = _198 && _201;
  if (!_202)   {
   int32_t _203 = _halide_buffer_get_min(_kernel2_buffer, 0);
   int32_t _204 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int32_t _205 = _204 + _203;
   int32_t _206 = _205 + -1;
   int32_t _207 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel2", 0, 0, 2, _203, _206);
   return _207;
  }
  int32_t _208 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  bool _209 = 0 <= _208;
  if (!_209)   {
   int32_t _210 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int32_t _211 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel2", 0, _210);
   return _211;
  }
  int32_t _212 = _halide_buffer_get_min(_kernel2_buffer, 1);
  bool _213 = _212 <= 0;
  int32_t _214 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  int32_t _215 = _214 + _212;
  bool _216 = 3 <= _215;
  bool _217 = _213 && _216;
  if (!_217)   {
   int32_t _218 = _halide_buffer_get_min(_kernel2_buffer, 1);
   int32_t _219 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int32_t _220 = _219 + _218;
   int32_t _221 = _220 + -1;
   int32_t _222 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel2", 1, 0, 2, _218, _221);
   return _222;
  }
  int32_t _223 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  bool _224 = 0 <= _223;
  if (!_224)   {
   int32_t _225 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int32_t _226 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel2", 1, _225);
   return _226;
  }
  int32_t _227 = _halide_buffer_get_min(_kernel2_buffer, 2);
  bool _228 = _227 <= 0;
  int32_t _229 = _halide_buffer_get_extent(_kernel2_buffer, 2);
  int32_t _230 = _229 + _227;
  bool _231 = 3 <= _230;
  bool _232 = _228 && _231;
  if (!_232)   {
   int32_t _233 = _halide_buffer_get_min(_kernel2_buffer, 2);
   int32_t _234 = _halide_buffer_get_extent(_kernel2_buffer, 2);
   int32_t _235 = _234 + _233;
   int32_t _236 = _235 + -1;
   int32_t _237 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel2", 2, 0, 2, _233, _236);
   return _237;
  }
  int32_t _238 = _halide_buffer_get_extent(_kernel2_buffer, 2);
  bool _239 = 0 <= _238;
  if (!_239)   {
   int32_t _240 = _halide_buffer_get_extent(_kernel2_buffer, 2);
   int32_t _241 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel2", 2, _240);
   return _241;
  }
  int32_t _242 = _halide_buffer_get_min(_kernel2_buffer, 3);
  bool _243 = _242 <= 0;
  int32_t _244 = _halide_buffer_get_extent(_kernel2_buffer, 3);
  int32_t _245 = _244 + _242;
  bool _246 = 3 <= _245;
  bool _247 = _243 && _246;
  if (!_247)   {
   int32_t _248 = _halide_buffer_get_min(_kernel2_buffer, 3);
   int32_t _249 = _halide_buffer_get_extent(_kernel2_buffer, 3);
   int32_t _250 = _249 + _248;
   int32_t _251 = _250 + -1;
   int32_t _252 = halide_error_access_out_of_bounds(_ucon, "Input buffer kernel2", 3, 0, 2, _248, _251);
   return _252;
  }
  int32_t _253 = _halide_buffer_get_extent(_kernel2_buffer, 3);
  bool _254 = 0 <= _253;
  if (!_254)   {
   int32_t _255 = _halide_buffer_get_extent(_kernel2_buffer, 3);
   int32_t _256 = halide_error_buffer_extents_negative(_ucon, "Input buffer kernel2", 3, _255);
   return _256;
  }
  int32_t _257 = _halide_buffer_get_min(_output_buffer, 0);
  bool _258 = _257 <= 0;
  int32_t _259 = _halide_buffer_get_extent(_output_buffer, 0);
  int32_t _260 = _259 + _257;
  bool _261 = 28 <= _260;
  bool _262 = _258 && _261;
  if (!_262)   {
   int32_t _263 = _halide_buffer_get_min(_output_buffer, 0);
   int32_t _264 = _halide_buffer_get_extent(_output_buffer, 0);
   int32_t _265 = _264 + _263;
   int32_t _266 = _265 + -1;
   int32_t _267 = halide_error_access_out_of_bounds(_ucon, "Output buffer output", 0, 0, 27, _263, _266);
   return _267;
  }
  int32_t _268 = _halide_buffer_get_extent(_output_buffer, 0);
  bool _269 = 0 <= _268;
  if (!_269)   {
   int32_t _270 = _halide_buffer_get_extent(_output_buffer, 0);
   int32_t _271 = halide_error_buffer_extents_negative(_ucon, "Output buffer output", 0, _270);
   return _271;
  }
  int32_t _272 = _halide_buffer_get_min(_output_buffer, 1);
  bool _273 = _272 <= 0;
  int32_t _274 = _halide_buffer_get_extent(_output_buffer, 1);
  int32_t _275 = _274 + _272;
  bool _276 = 28 <= _275;
  bool _277 = _273 && _276;
  if (!_277)   {
   int32_t _278 = _halide_buffer_get_min(_output_buffer, 1);
   int32_t _279 = _halide_buffer_get_extent(_output_buffer, 1);
   int32_t _280 = _279 + _278;
   int32_t _281 = _280 + -1;
   int32_t _282 = halide_error_access_out_of_bounds(_ucon, "Output buffer output", 1, 0, 27, _278, _281);
   return _282;
  }
  int32_t _283 = _halide_buffer_get_extent(_output_buffer, 1);
  bool _284 = 0 <= _283;
  if (!_284)   {
   int32_t _285 = _halide_buffer_get_extent(_output_buffer, 1);
   int32_t _286 = halide_error_buffer_extents_negative(_ucon, "Output buffer output", 1, _285);
   return _286;
  }
  int32_t _287 = _halide_buffer_get_min(_output_buffer, 2);
  bool _288 = _287 <= 0;
  int32_t _289 = _halide_buffer_get_extent(_output_buffer, 2);
  int32_t _290 = _289 + _287;
  bool _291 = 3 <= _290;
  bool _292 = _288 && _291;
  if (!_292)   {
   int32_t _293 = _halide_buffer_get_min(_output_buffer, 2);
   int32_t _294 = _halide_buffer_get_extent(_output_buffer, 2);
   int32_t _295 = _294 + _293;
   int32_t _296 = _295 + -1;
   int32_t _297 = halide_error_access_out_of_bounds(_ucon, "Output buffer output", 2, 0, 2, _293, _296);
   return _297;
  }
  int32_t _298 = _halide_buffer_get_extent(_output_buffer, 2);
  bool _299 = 0 <= _298;
  if (!_299)   {
   int32_t _300 = _halide_buffer_get_extent(_output_buffer, 2);
   int32_t _301 = halide_error_buffer_extents_negative(_ucon, "Output buffer output", 2, _300);
   return _301;
  }
  int32_t _302 = _halide_buffer_get_stride(_input_buffer, 0);
  bool _303 = _302 == 1;
  if (!_303)   {
   int32_t _304 = _halide_buffer_get_stride(_input_buffer, 0);
   int32_t _305 = halide_error_constraint_violated(_ucon, "input.stride.0", _304, "1", 1);
   return _305;
  }
  int32_t _306 = _halide_buffer_get_stride(_kernel_buffer, 0);
  bool _307 = _306 == 1;
  if (!_307)   {
   int32_t _308 = _halide_buffer_get_stride(_kernel_buffer, 0);
   int32_t _309 = halide_error_constraint_violated(_ucon, "kernel.stride.0", _308, "1", 1);
   return _309;
  }
  int32_t _310 = _halide_buffer_get_stride(_kernel2_buffer, 0);
  bool _311 = _310 == 1;
  if (!_311)   {
   int32_t _312 = _halide_buffer_get_stride(_kernel2_buffer, 0);
   int32_t _313 = halide_error_constraint_violated(_ucon, "kernel2.stride.0", _312, "1", 1);
   return _313;
  }
  int32_t _314 = _halide_buffer_get_stride(_output_buffer, 0);
  bool _315 = _314 == 1;
  if (!_315)   {
   int32_t _316 = _halide_buffer_get_stride(_output_buffer, 0);
   int32_t _317 = halide_error_constraint_violated(_ucon, "output.stride.0", _316, "1", 1);
   return _317;
  }
  int32_t _318 = _halide_buffer_get_extent(_input_buffer, 0);
  int64_t _319 = (int64_t)(_318);
  int64_t _320 = (int64_t)(0);
  int64_t _321 = _320 - _319;
  bool _322 = _319 > _320;
  int64_t _323 = (int64_t)(_322 ? _319 : _321);
  uint64_t _324 = (uint64_t)(_323);
  uint64_t _325 = _324;
  uint64_t _326 = (uint64_t)(2147483647);
  bool _327 = _325 <= _326;
  if (!_327)   {
   int32_t _328 = _halide_buffer_get_extent(_input_buffer, 0);
   int64_t _329 = (int64_t)(_328);
   int64_t _330 = (int64_t)(0);
   int64_t _331 = _330 - _329;
   bool _332 = _329 > _330;
   int64_t _333 = (int64_t)(_332 ? _329 : _331);
   uint64_t _334 = (uint64_t)(_333);
   uint64_t _335 = _334;
   uint64_t _336 = (uint64_t)(2147483647);
   int32_t _337 = halide_error_buffer_allocation_too_large(_ucon, "input", _335, _336);
   return _337;
  }
  int32_t _338 = _halide_buffer_get_extent(_input_buffer, 1);
  int64_t _339 = (int64_t)(_338);
  int32_t _340 = _halide_buffer_get_stride(_input_buffer, 1);
  int64_t _341 = (int64_t)(_340);
  int64_t _342 = _339 * _341;
  int64_t _343 = (int64_t)(0);
  int64_t _344 = _343 - _342;
  bool _345 = _342 > _343;
  int64_t _346 = (int64_t)(_345 ? _342 : _344);
  uint64_t _347 = (uint64_t)(_346);
  uint64_t _348 = _347;
  uint64_t _349 = (uint64_t)(2147483647);
  bool _350 = _348 <= _349;
  if (!_350)   {
   int32_t _351 = _halide_buffer_get_extent(_input_buffer, 1);
   int64_t _352 = (int64_t)(_351);
   int32_t _353 = _halide_buffer_get_stride(_input_buffer, 1);
   int64_t _354 = (int64_t)(_353);
   int64_t _355 = _352 * _354;
   int64_t _356 = (int64_t)(0);
   int64_t _357 = _356 - _355;
   bool _358 = _355 > _356;
   int64_t _359 = (int64_t)(_358 ? _355 : _357);
   uint64_t _360 = (uint64_t)(_359);
   uint64_t _361 = _360;
   uint64_t _362 = (uint64_t)(2147483647);
   int32_t _363 = halide_error_buffer_allocation_too_large(_ucon, "input", _361, _362);
   return _363;
  }
  int32_t _364 = _halide_buffer_get_extent(_input_buffer, 1);
  int64_t _365 = (int64_t)(_364);
  int32_t _366 = _halide_buffer_get_extent(_input_buffer, 0);
  int64_t _367 = (int64_t)(_366);
  int64_t _368 = _365 * _367;
  int64_t _369 = (int64_t)(2147483647);
  bool _370 = _368 <= _369;
  if (!_370)   {
   int32_t _371 = _halide_buffer_get_extent(_input_buffer, 1);
   int64_t _372 = (int64_t)(_371);
   int32_t _373 = _halide_buffer_get_extent(_input_buffer, 0);
   int64_t _374 = (int64_t)(_373);
   int64_t _375 = _372 * _374;
   int64_t _376 = (int64_t)(2147483647);
   int32_t _377 = halide_error_buffer_extents_too_large(_ucon, "input", _375, _376);
   return _377;
  }
  int32_t _378 = _halide_buffer_get_extent(_input_buffer, 2);
  int64_t _379 = (int64_t)(_378);
  int32_t _380 = _halide_buffer_get_stride(_input_buffer, 2);
  int64_t _381 = (int64_t)(_380);
  int64_t _382 = _379 * _381;
  int64_t _383 = (int64_t)(0);
  int64_t _384 = _383 - _382;
  bool _385 = _382 > _383;
  int64_t _386 = (int64_t)(_385 ? _382 : _384);
  uint64_t _387 = (uint64_t)(_386);
  uint64_t _388 = _387;
  uint64_t _389 = (uint64_t)(2147483647);
  bool _390 = _388 <= _389;
  if (!_390)   {
   int32_t _391 = _halide_buffer_get_extent(_input_buffer, 2);
   int64_t _392 = (int64_t)(_391);
   int32_t _393 = _halide_buffer_get_stride(_input_buffer, 2);
   int64_t _394 = (int64_t)(_393);
   int64_t _395 = _392 * _394;
   int64_t _396 = (int64_t)(0);
   int64_t _397 = _396 - _395;
   bool _398 = _395 > _396;
   int64_t _399 = (int64_t)(_398 ? _395 : _397);
   uint64_t _400 = (uint64_t)(_399);
   uint64_t _401 = _400;
   uint64_t _402 = (uint64_t)(2147483647);
   int32_t _403 = halide_error_buffer_allocation_too_large(_ucon, "input", _401, _402);
   return _403;
  }
  int32_t _404 = _halide_buffer_get_extent(_input_buffer, 1);
  int64_t _405 = (int64_t)(_404);
  int32_t _406 = _halide_buffer_get_extent(_input_buffer, 0);
  int64_t _407 = (int64_t)(_406);
  int64_t _408 = _405 * _407;
  int32_t _409 = _halide_buffer_get_extent(_input_buffer, 2);
  int64_t _410 = (int64_t)(_409);
  int64_t _411 = _408 * _410;
  int64_t _412 = (int64_t)(2147483647);
  bool _413 = _411 <= _412;
  if (!_413)   {
   int32_t _414 = _halide_buffer_get_extent(_input_buffer, 1);
   int64_t _415 = (int64_t)(_414);
   int32_t _416 = _halide_buffer_get_extent(_input_buffer, 0);
   int64_t _417 = (int64_t)(_416);
   int64_t _418 = _415 * _417;
   int32_t _419 = _halide_buffer_get_extent(_input_buffer, 2);
   int64_t _420 = (int64_t)(_419);
   int64_t _421 = _418 * _420;
   int64_t _422 = (int64_t)(2147483647);
   int32_t _423 = halide_error_buffer_extents_too_large(_ucon, "input", _421, _422);
   return _423;
  }
  int32_t _424 = _halide_buffer_get_extent(_kernel_buffer, 0);
  int64_t _425 = (int64_t)(_424);
  int64_t _426 = (int64_t)(0);
  int64_t _427 = _426 - _425;
  bool _428 = _425 > _426;
  int64_t _429 = (int64_t)(_428 ? _425 : _427);
  uint64_t _430 = (uint64_t)(_429);
  uint64_t _431 = _430;
  uint64_t _432 = (uint64_t)(2147483647);
  bool _433 = _431 <= _432;
  if (!_433)   {
   int32_t _434 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int64_t _435 = (int64_t)(_434);
   int64_t _436 = (int64_t)(0);
   int64_t _437 = _436 - _435;
   bool _438 = _435 > _436;
   int64_t _439 = (int64_t)(_438 ? _435 : _437);
   uint64_t _440 = (uint64_t)(_439);
   uint64_t _441 = _440;
   uint64_t _442 = (uint64_t)(2147483647);
   int32_t _443 = halide_error_buffer_allocation_too_large(_ucon, "kernel", _441, _442);
   return _443;
  }
  int32_t _444 = _halide_buffer_get_extent(_kernel_buffer, 1);
  int64_t _445 = (int64_t)(_444);
  int32_t _446 = _halide_buffer_get_stride(_kernel_buffer, 1);
  int64_t _447 = (int64_t)(_446);
  int64_t _448 = _445 * _447;
  int64_t _449 = (int64_t)(0);
  int64_t _450 = _449 - _448;
  bool _451 = _448 > _449;
  int64_t _452 = (int64_t)(_451 ? _448 : _450);
  uint64_t _453 = (uint64_t)(_452);
  uint64_t _454 = _453;
  uint64_t _455 = (uint64_t)(2147483647);
  bool _456 = _454 <= _455;
  if (!_456)   {
   int32_t _457 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int64_t _458 = (int64_t)(_457);
   int32_t _459 = _halide_buffer_get_stride(_kernel_buffer, 1);
   int64_t _460 = (int64_t)(_459);
   int64_t _461 = _458 * _460;
   int64_t _462 = (int64_t)(0);
   int64_t _463 = _462 - _461;
   bool _464 = _461 > _462;
   int64_t _465 = (int64_t)(_464 ? _461 : _463);
   uint64_t _466 = (uint64_t)(_465);
   uint64_t _467 = _466;
   uint64_t _468 = (uint64_t)(2147483647);
   int32_t _469 = halide_error_buffer_allocation_too_large(_ucon, "kernel", _467, _468);
   return _469;
  }
  int32_t _470 = _halide_buffer_get_extent(_kernel_buffer, 1);
  int64_t _471 = (int64_t)(_470);
  int32_t _472 = _halide_buffer_get_extent(_kernel_buffer, 0);
  int64_t _473 = (int64_t)(_472);
  int64_t _474 = _471 * _473;
  int64_t _475 = (int64_t)(2147483647);
  bool _476 = _474 <= _475;
  if (!_476)   {
   int32_t _477 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int64_t _478 = (int64_t)(_477);
   int32_t _479 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int64_t _480 = (int64_t)(_479);
   int64_t _481 = _478 * _480;
   int64_t _482 = (int64_t)(2147483647);
   int32_t _483 = halide_error_buffer_extents_too_large(_ucon, "kernel", _481, _482);
   return _483;
  }
  int32_t _484 = _halide_buffer_get_extent(_kernel_buffer, 2);
  int64_t _485 = (int64_t)(_484);
  int32_t _486 = _halide_buffer_get_stride(_kernel_buffer, 2);
  int64_t _487 = (int64_t)(_486);
  int64_t _488 = _485 * _487;
  int64_t _489 = (int64_t)(0);
  int64_t _490 = _489 - _488;
  bool _491 = _488 > _489;
  int64_t _492 = (int64_t)(_491 ? _488 : _490);
  uint64_t _493 = (uint64_t)(_492);
  uint64_t _494 = _493;
  uint64_t _495 = (uint64_t)(2147483647);
  bool _496 = _494 <= _495;
  if (!_496)   {
   int32_t _497 = _halide_buffer_get_extent(_kernel_buffer, 2);
   int64_t _498 = (int64_t)(_497);
   int32_t _499 = _halide_buffer_get_stride(_kernel_buffer, 2);
   int64_t _500 = (int64_t)(_499);
   int64_t _501 = _498 * _500;
   int64_t _502 = (int64_t)(0);
   int64_t _503 = _502 - _501;
   bool _504 = _501 > _502;
   int64_t _505 = (int64_t)(_504 ? _501 : _503);
   uint64_t _506 = (uint64_t)(_505);
   uint64_t _507 = _506;
   uint64_t _508 = (uint64_t)(2147483647);
   int32_t _509 = halide_error_buffer_allocation_too_large(_ucon, "kernel", _507, _508);
   return _509;
  }
  int32_t _510 = _halide_buffer_get_extent(_kernel_buffer, 1);
  int64_t _511 = (int64_t)(_510);
  int32_t _512 = _halide_buffer_get_extent(_kernel_buffer, 0);
  int64_t _513 = (int64_t)(_512);
  int64_t _514 = _511 * _513;
  int32_t _515 = _halide_buffer_get_extent(_kernel_buffer, 2);
  int64_t _516 = (int64_t)(_515);
  int64_t _517 = _514 * _516;
  int64_t _518 = (int64_t)(2147483647);
  bool _519 = _517 <= _518;
  if (!_519)   {
   int32_t _520 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int64_t _521 = (int64_t)(_520);
   int32_t _522 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int64_t _523 = (int64_t)(_522);
   int64_t _524 = _521 * _523;
   int32_t _525 = _halide_buffer_get_extent(_kernel_buffer, 2);
   int64_t _526 = (int64_t)(_525);
   int64_t _527 = _524 * _526;
   int64_t _528 = (int64_t)(2147483647);
   int32_t _529 = halide_error_buffer_extents_too_large(_ucon, "kernel", _527, _528);
   return _529;
  }
  int32_t _530 = _halide_buffer_get_extent(_kernel_buffer, 3);
  int64_t _531 = (int64_t)(_530);
  int32_t _532 = _halide_buffer_get_stride(_kernel_buffer, 3);
  int64_t _533 = (int64_t)(_532);
  int64_t _534 = _531 * _533;
  int64_t _535 = (int64_t)(0);
  int64_t _536 = _535 - _534;
  bool _537 = _534 > _535;
  int64_t _538 = (int64_t)(_537 ? _534 : _536);
  uint64_t _539 = (uint64_t)(_538);
  uint64_t _540 = _539;
  uint64_t _541 = (uint64_t)(2147483647);
  bool _542 = _540 <= _541;
  if (!_542)   {
   int32_t _543 = _halide_buffer_get_extent(_kernel_buffer, 3);
   int64_t _544 = (int64_t)(_543);
   int32_t _545 = _halide_buffer_get_stride(_kernel_buffer, 3);
   int64_t _546 = (int64_t)(_545);
   int64_t _547 = _544 * _546;
   int64_t _548 = (int64_t)(0);
   int64_t _549 = _548 - _547;
   bool _550 = _547 > _548;
   int64_t _551 = (int64_t)(_550 ? _547 : _549);
   uint64_t _552 = (uint64_t)(_551);
   uint64_t _553 = _552;
   uint64_t _554 = (uint64_t)(2147483647);
   int32_t _555 = halide_error_buffer_allocation_too_large(_ucon, "kernel", _553, _554);
   return _555;
  }
  int32_t _556 = _halide_buffer_get_extent(_kernel_buffer, 1);
  int64_t _557 = (int64_t)(_556);
  int32_t _558 = _halide_buffer_get_extent(_kernel_buffer, 0);
  int64_t _559 = (int64_t)(_558);
  int64_t _560 = _557 * _559;
  int32_t _561 = _halide_buffer_get_extent(_kernel_buffer, 2);
  int64_t _562 = (int64_t)(_561);
  int64_t _563 = _560 * _562;
  int32_t _564 = _halide_buffer_get_extent(_kernel_buffer, 3);
  int64_t _565 = (int64_t)(_564);
  int64_t _566 = _563 * _565;
  int64_t _567 = (int64_t)(2147483647);
  bool _568 = _566 <= _567;
  if (!_568)   {
   int32_t _569 = _halide_buffer_get_extent(_kernel_buffer, 1);
   int64_t _570 = (int64_t)(_569);
   int32_t _571 = _halide_buffer_get_extent(_kernel_buffer, 0);
   int64_t _572 = (int64_t)(_571);
   int64_t _573 = _570 * _572;
   int32_t _574 = _halide_buffer_get_extent(_kernel_buffer, 2);
   int64_t _575 = (int64_t)(_574);
   int64_t _576 = _573 * _575;
   int32_t _577 = _halide_buffer_get_extent(_kernel_buffer, 3);
   int64_t _578 = (int64_t)(_577);
   int64_t _579 = _576 * _578;
   int64_t _580 = (int64_t)(2147483647);
   int32_t _581 = halide_error_buffer_extents_too_large(_ucon, "kernel", _579, _580);
   return _581;
  }
  int32_t _582 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  int64_t _583 = (int64_t)(_582);
  int64_t _584 = (int64_t)(0);
  int64_t _585 = _584 - _583;
  bool _586 = _583 > _584;
  int64_t _587 = (int64_t)(_586 ? _583 : _585);
  uint64_t _588 = (uint64_t)(_587);
  uint64_t _589 = _588;
  uint64_t _590 = (uint64_t)(2147483647);
  bool _591 = _589 <= _590;
  if (!_591)   {
   int32_t _592 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int64_t _593 = (int64_t)(_592);
   int64_t _594 = (int64_t)(0);
   int64_t _595 = _594 - _593;
   bool _596 = _593 > _594;
   int64_t _597 = (int64_t)(_596 ? _593 : _595);
   uint64_t _598 = (uint64_t)(_597);
   uint64_t _599 = _598;
   uint64_t _600 = (uint64_t)(2147483647);
   int32_t _601 = halide_error_buffer_allocation_too_large(_ucon, "kernel2", _599, _600);
   return _601;
  }
  int32_t _602 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  int64_t _603 = (int64_t)(_602);
  int32_t _604 = _halide_buffer_get_stride(_kernel2_buffer, 1);
  int64_t _605 = (int64_t)(_604);
  int64_t _606 = _603 * _605;
  int64_t _607 = (int64_t)(0);
  int64_t _608 = _607 - _606;
  bool _609 = _606 > _607;
  int64_t _610 = (int64_t)(_609 ? _606 : _608);
  uint64_t _611 = (uint64_t)(_610);
  uint64_t _612 = _611;
  uint64_t _613 = (uint64_t)(2147483647);
  bool _614 = _612 <= _613;
  if (!_614)   {
   int32_t _615 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int64_t _616 = (int64_t)(_615);
   int32_t _617 = _halide_buffer_get_stride(_kernel2_buffer, 1);
   int64_t _618 = (int64_t)(_617);
   int64_t _619 = _616 * _618;
   int64_t _620 = (int64_t)(0);
   int64_t _621 = _620 - _619;
   bool _622 = _619 > _620;
   int64_t _623 = (int64_t)(_622 ? _619 : _621);
   uint64_t _624 = (uint64_t)(_623);
   uint64_t _625 = _624;
   uint64_t _626 = (uint64_t)(2147483647);
   int32_t _627 = halide_error_buffer_allocation_too_large(_ucon, "kernel2", _625, _626);
   return _627;
  }
  int32_t _628 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  int64_t _629 = (int64_t)(_628);
  int32_t _630 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  int64_t _631 = (int64_t)(_630);
  int64_t _632 = _629 * _631;
  int64_t _633 = (int64_t)(2147483647);
  bool _634 = _632 <= _633;
  if (!_634)   {
   int32_t _635 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int64_t _636 = (int64_t)(_635);
   int32_t _637 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int64_t _638 = (int64_t)(_637);
   int64_t _639 = _636 * _638;
   int64_t _640 = (int64_t)(2147483647);
   int32_t _641 = halide_error_buffer_extents_too_large(_ucon, "kernel2", _639, _640);
   return _641;
  }
  int32_t _642 = _halide_buffer_get_extent(_kernel2_buffer, 2);
  int64_t _643 = (int64_t)(_642);
  int32_t _644 = _halide_buffer_get_stride(_kernel2_buffer, 2);
  int64_t _645 = (int64_t)(_644);
  int64_t _646 = _643 * _645;
  int64_t _647 = (int64_t)(0);
  int64_t _648 = _647 - _646;
  bool _649 = _646 > _647;
  int64_t _650 = (int64_t)(_649 ? _646 : _648);
  uint64_t _651 = (uint64_t)(_650);
  uint64_t _652 = _651;
  uint64_t _653 = (uint64_t)(2147483647);
  bool _654 = _652 <= _653;
  if (!_654)   {
   int32_t _655 = _halide_buffer_get_extent(_kernel2_buffer, 2);
   int64_t _656 = (int64_t)(_655);
   int32_t _657 = _halide_buffer_get_stride(_kernel2_buffer, 2);
   int64_t _658 = (int64_t)(_657);
   int64_t _659 = _656 * _658;
   int64_t _660 = (int64_t)(0);
   int64_t _661 = _660 - _659;
   bool _662 = _659 > _660;
   int64_t _663 = (int64_t)(_662 ? _659 : _661);
   uint64_t _664 = (uint64_t)(_663);
   uint64_t _665 = _664;
   uint64_t _666 = (uint64_t)(2147483647);
   int32_t _667 = halide_error_buffer_allocation_too_large(_ucon, "kernel2", _665, _666);
   return _667;
  }
  int32_t _668 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  int64_t _669 = (int64_t)(_668);
  int32_t _670 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  int64_t _671 = (int64_t)(_670);
  int64_t _672 = _669 * _671;
  int32_t _673 = _halide_buffer_get_extent(_kernel2_buffer, 2);
  int64_t _674 = (int64_t)(_673);
  int64_t _675 = _672 * _674;
  int64_t _676 = (int64_t)(2147483647);
  bool _677 = _675 <= _676;
  if (!_677)   {
   int32_t _678 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int64_t _679 = (int64_t)(_678);
   int32_t _680 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int64_t _681 = (int64_t)(_680);
   int64_t _682 = _679 * _681;
   int32_t _683 = _halide_buffer_get_extent(_kernel2_buffer, 2);
   int64_t _684 = (int64_t)(_683);
   int64_t _685 = _682 * _684;
   int64_t _686 = (int64_t)(2147483647);
   int32_t _687 = halide_error_buffer_extents_too_large(_ucon, "kernel2", _685, _686);
   return _687;
  }
  int32_t _688 = _halide_buffer_get_extent(_kernel2_buffer, 3);
  int64_t _689 = (int64_t)(_688);
  int32_t _690 = _halide_buffer_get_stride(_kernel2_buffer, 3);
  int64_t _691 = (int64_t)(_690);
  int64_t _692 = _689 * _691;
  int64_t _693 = (int64_t)(0);
  int64_t _694 = _693 - _692;
  bool _695 = _692 > _693;
  int64_t _696 = (int64_t)(_695 ? _692 : _694);
  uint64_t _697 = (uint64_t)(_696);
  uint64_t _698 = _697;
  uint64_t _699 = (uint64_t)(2147483647);
  bool _700 = _698 <= _699;
  if (!_700)   {
   int32_t _701 = _halide_buffer_get_extent(_kernel2_buffer, 3);
   int64_t _702 = (int64_t)(_701);
   int32_t _703 = _halide_buffer_get_stride(_kernel2_buffer, 3);
   int64_t _704 = (int64_t)(_703);
   int64_t _705 = _702 * _704;
   int64_t _706 = (int64_t)(0);
   int64_t _707 = _706 - _705;
   bool _708 = _705 > _706;
   int64_t _709 = (int64_t)(_708 ? _705 : _707);
   uint64_t _710 = (uint64_t)(_709);
   uint64_t _711 = _710;
   uint64_t _712 = (uint64_t)(2147483647);
   int32_t _713 = halide_error_buffer_allocation_too_large(_ucon, "kernel2", _711, _712);
   return _713;
  }
  int32_t _714 = _halide_buffer_get_extent(_kernel2_buffer, 1);
  int64_t _715 = (int64_t)(_714);
  int32_t _716 = _halide_buffer_get_extent(_kernel2_buffer, 0);
  int64_t _717 = (int64_t)(_716);
  int64_t _718 = _715 * _717;
  int32_t _719 = _halide_buffer_get_extent(_kernel2_buffer, 2);
  int64_t _720 = (int64_t)(_719);
  int64_t _721 = _718 * _720;
  int32_t _722 = _halide_buffer_get_extent(_kernel2_buffer, 3);
  int64_t _723 = (int64_t)(_722);
  int64_t _724 = _721 * _723;
  int64_t _725 = (int64_t)(2147483647);
  bool _726 = _724 <= _725;
  if (!_726)   {
   int32_t _727 = _halide_buffer_get_extent(_kernel2_buffer, 1);
   int64_t _728 = (int64_t)(_727);
   int32_t _729 = _halide_buffer_get_extent(_kernel2_buffer, 0);
   int64_t _730 = (int64_t)(_729);
   int64_t _731 = _728 * _730;
   int32_t _732 = _halide_buffer_get_extent(_kernel2_buffer, 2);
   int64_t _733 = (int64_t)(_732);
   int64_t _734 = _731 * _733;
   int32_t _735 = _halide_buffer_get_extent(_kernel2_buffer, 3);
   int64_t _736 = (int64_t)(_735);
   int64_t _737 = _734 * _736;
   int64_t _738 = (int64_t)(2147483647);
   int32_t _739 = halide_error_buffer_extents_too_large(_ucon, "kernel2", _737, _738);
   return _739;
  }
  int32_t _740 = _halide_buffer_get_extent(_output_buffer, 0);
  int64_t _741 = (int64_t)(_740);
  int64_t _742 = (int64_t)(0);
  int64_t _743 = _742 - _741;
  bool _744 = _741 > _742;
  int64_t _745 = (int64_t)(_744 ? _741 : _743);
  uint64_t _746 = (uint64_t)(_745);
  uint64_t _747 = _746;
  uint64_t _748 = (uint64_t)(2147483647);
  bool _749 = _747 <= _748;
  if (!_749)   {
   int32_t _750 = _halide_buffer_get_extent(_output_buffer, 0);
   int64_t _751 = (int64_t)(_750);
   int64_t _752 = (int64_t)(0);
   int64_t _753 = _752 - _751;
   bool _754 = _751 > _752;
   int64_t _755 = (int64_t)(_754 ? _751 : _753);
   uint64_t _756 = (uint64_t)(_755);
   uint64_t _757 = _756;
   uint64_t _758 = (uint64_t)(2147483647);
   int32_t _759 = halide_error_buffer_allocation_too_large(_ucon, "output", _757, _758);
   return _759;
  }
  int32_t _760 = _halide_buffer_get_extent(_output_buffer, 1);
  int64_t _761 = (int64_t)(_760);
  int32_t _762 = _halide_buffer_get_stride(_output_buffer, 1);
  int64_t _763 = (int64_t)(_762);
  int64_t _764 = _761 * _763;
  int64_t _765 = (int64_t)(0);
  int64_t _766 = _765 - _764;
  bool _767 = _764 > _765;
  int64_t _768 = (int64_t)(_767 ? _764 : _766);
  uint64_t _769 = (uint64_t)(_768);
  uint64_t _770 = _769;
  uint64_t _771 = (uint64_t)(2147483647);
  bool _772 = _770 <= _771;
  if (!_772)   {
   int32_t _773 = _halide_buffer_get_extent(_output_buffer, 1);
   int64_t _774 = (int64_t)(_773);
   int32_t _775 = _halide_buffer_get_stride(_output_buffer, 1);
   int64_t _776 = (int64_t)(_775);
   int64_t _777 = _774 * _776;
   int64_t _778 = (int64_t)(0);
   int64_t _779 = _778 - _777;
   bool _780 = _777 > _778;
   int64_t _781 = (int64_t)(_780 ? _777 : _779);
   uint64_t _782 = (uint64_t)(_781);
   uint64_t _783 = _782;
   uint64_t _784 = (uint64_t)(2147483647);
   int32_t _785 = halide_error_buffer_allocation_too_large(_ucon, "output", _783, _784);
   return _785;
  }
  int32_t _786 = _halide_buffer_get_extent(_output_buffer, 1);
  int64_t _787 = (int64_t)(_786);
  int32_t _788 = _halide_buffer_get_extent(_output_buffer, 0);
  int64_t _789 = (int64_t)(_788);
  int64_t _790 = _787 * _789;
  int64_t _791 = (int64_t)(2147483647);
  bool _792 = _790 <= _791;
  if (!_792)   {
   int32_t _793 = _halide_buffer_get_extent(_output_buffer, 1);
   int64_t _794 = (int64_t)(_793);
   int32_t _795 = _halide_buffer_get_extent(_output_buffer, 0);
   int64_t _796 = (int64_t)(_795);
   int64_t _797 = _794 * _796;
   int64_t _798 = (int64_t)(2147483647);
   int32_t _799 = halide_error_buffer_extents_too_large(_ucon, "output", _797, _798);
   return _799;
  }
  int32_t _800 = _halide_buffer_get_extent(_output_buffer, 2);
  int64_t _801 = (int64_t)(_800);
  int32_t _802 = _halide_buffer_get_stride(_output_buffer, 2);
  int64_t _803 = (int64_t)(_802);
  int64_t _804 = _801 * _803;
  int64_t _805 = (int64_t)(0);
  int64_t _806 = _805 - _804;
  bool _807 = _804 > _805;
  int64_t _808 = (int64_t)(_807 ? _804 : _806);
  uint64_t _809 = (uint64_t)(_808);
  uint64_t _810 = _809;
  uint64_t _811 = (uint64_t)(2147483647);
  bool _812 = _810 <= _811;
  if (!_812)   {
   int32_t _813 = _halide_buffer_get_extent(_output_buffer, 2);
   int64_t _814 = (int64_t)(_813);
   int32_t _815 = _halide_buffer_get_stride(_output_buffer, 2);
   int64_t _816 = (int64_t)(_815);
   int64_t _817 = _814 * _816;
   int64_t _818 = (int64_t)(0);
   int64_t _819 = _818 - _817;
   bool _820 = _817 > _818;
   int64_t _821 = (int64_t)(_820 ? _817 : _819);
   uint64_t _822 = (uint64_t)(_821);
   uint64_t _823 = _822;
   uint64_t _824 = (uint64_t)(2147483647);
   int32_t _825 = halide_error_buffer_allocation_too_large(_ucon, "output", _823, _824);
   return _825;
  }
  int32_t _826 = _halide_buffer_get_extent(_output_buffer, 1);
  int64_t _827 = (int64_t)(_826);
  int32_t _828 = _halide_buffer_get_extent(_output_buffer, 0);
  int64_t _829 = (int64_t)(_828);
  int64_t _830 = _827 * _829;
  int32_t _831 = _halide_buffer_get_extent(_output_buffer, 2);
  int64_t _832 = (int64_t)(_831);
  int64_t _833 = _830 * _832;
  int64_t _834 = (int64_t)(2147483647);
  bool _835 = _833 <= _834;
  if (!_835)   {
   int32_t _836 = _halide_buffer_get_extent(_output_buffer, 1);
   int64_t _837 = (int64_t)(_836);
   int32_t _838 = _halide_buffer_get_extent(_output_buffer, 0);
   int64_t _839 = (int64_t)(_838);
   int64_t _840 = _837 * _839;
   int32_t _841 = _halide_buffer_get_extent(_output_buffer, 2);
   int64_t _842 = (int64_t)(_841);
   int64_t _843 = _840 * _842;
   int64_t _844 = (int64_t)(2147483647);
   int32_t _845 = halide_error_buffer_extents_too_large(_ucon, "output", _843, _844);
   return _845;
  }
  void *_846 = _halide_buffer_get_host(_input_buffer);
  uint64_t _847 = (uint64_t)(0);
  void *_848 = (void *)(_847);
  bool _849 = _846 != _848;
  if (!_849)   {
   int32_t _850 = halide_error_host_is_null(_ucon, "Input buffer input");
   return _850;
  }
  void *_851 = _halide_buffer_get_host(_kernel_buffer);
  uint64_t _852 = (uint64_t)(0);
  void *_853 = (void *)(_852);
  bool _854 = _851 != _853;
  if (!_854)   {
   int32_t _855 = halide_error_host_is_null(_ucon, "Input buffer kernel");
   return _855;
  }
  void *_856 = _halide_buffer_get_host(_kernel2_buffer);
  uint64_t _857 = (uint64_t)(0);
  void *_858 = (void *)(_857);
  bool _859 = _856 != _858;
  if (!_859)   {
   int32_t _860 = halide_error_host_is_null(_ucon, "Input buffer kernel2");
   return _860;
  }
  void *_861 = _halide_buffer_get_host(_output_buffer);
  uint64_t _862 = (uint64_t)(0);
  void *_863 = (void *)(_862);
  bool _864 = _861 != _863;
  if (!_864)   {
   int32_t _865 = halide_error_host_is_null(_ucon, "Output buffer output");
   return _865;
  }
  // get host pointers for input/output halide buffers
  void *_input = _halide_buffer_get_host(_input_buffer);
  void *_kernel = _halide_buffer_get_host(_kernel_buffer);
  void *_kernel2 = _halide_buffer_get_host(_kernel2_buffer);
  void *_output = _halide_buffer_get_host(_output_buffer);

  // Allocate shared buffer for _hw_kernel2_stencil
  RDAI_MemObject *_hw_kernel2_stencil = RDAI_mem_shared_allocate(162);
  // produce hw_kernel2.stencil
  for (int _hw_kernel2_s0_y = 0; _hw_kernel2_s0_y < 0 + 3; _hw_kernel2_s0_y++)
  {
   for (int _hw_kernel2_s0_x = 0; _hw_kernel2_s0_x < 0 + 3; _hw_kernel2_s0_x++)
   {
    for (int _hw_kernel2_s0_w = 0; _hw_kernel2_s0_w < 0 + 3; _hw_kernel2_s0_w++)
    {
     for (int _hw_kernel2_s0_z = 0; _hw_kernel2_s0_z < 0 + 3; _hw_kernel2_s0_z++)
     {
      // Provision buffer _hw_kernel2_stencil
      int32_t _866 = _halide_buffer_get_stride(_kernel2_buffer, 1);
      int32_t _867 = _866 * _hw_kernel2_s0_w;
      int32_t _868 = _halide_buffer_get_stride(_kernel2_buffer, 2);
      int32_t _869 = _868 * _hw_kernel2_s0_x;
      int32_t _870 = _halide_buffer_get_stride(_kernel2_buffer, 3);
      int32_t _871 = _870 * _hw_kernel2_s0_y;
      int32_t _872 = _halide_buffer_get_min(_kernel2_buffer, 1);
      int32_t _873 = _872 * _866;
      int32_t _874 = _halide_buffer_get_min(_kernel2_buffer, 0);
      int32_t _875 = _halide_buffer_get_min(_kernel2_buffer, 3);
      int32_t _876 = _875 * _870;
      int32_t _877 = _halide_buffer_get_min(_kernel2_buffer, 2);
      int32_t _878 = _877 * _868;
      int32_t _879 = _876 + _878;
      int32_t _880 = _874 + _879;
      int32_t _881 = _873 + _880;
      int32_t _882 = _871 - _881;
      int32_t _883 = _869 + _882;
      int32_t _884 = _867 + _883;
      int32_t _885 = _884 + _hw_kernel2_s0_z;
      uint8_t _886 = ((const uint8_t *)_kernel2)[_885];
      uint16_t _887 = (uint16_t)(_886);
_887;
      uint16_t *_hw_kernel2_stencil_host = (uint16_t *) _hw_kernel2_stencil->host_ptr;
      int32_t _888 = _hw_kernel2_s0_y * 27;
      int32_t _889 = _hw_kernel2_s0_x * 9;
      int32_t _890 = _hw_kernel2_s0_w * 3;
      int32_t _891 = _890 + _hw_kernel2_s0_z;
      int32_t _892 = _889 + _891;
      int32_t _893 = _888 + _892;
_893;
      _hw_kernel2_stencil_host[_893] = _887;
     } // for _hw_kernel2_s0_z
    } // for _hw_kernel2_s0_w
   } // for _hw_kernel2_s0_x
  } // for _hw_kernel2_s0_y
  // consume hw_kernel2.stencil
  // Allocate shared buffer for _hw_input_stencil
  RDAI_MemObject *_hw_input_stencil = RDAI_mem_shared_allocate(6144);
  // produce hw_input.stencil
  for (int _hw_input_s0_y = 0; _hw_input_s0_y < 0 + 32; _hw_input_s0_y++)
  {
   for (int _hw_input_s0_x = 0; _hw_input_s0_x < 0 + 32; _hw_input_s0_x++)
   {
    for (int _hw_input_s0_z = 0; _hw_input_s0_z < 0 + 3; _hw_input_s0_z++)
    {
     // Provision buffer _hw_input_stencil
     int32_t _894 = _halide_buffer_get_stride(_input_buffer, 1);
     int32_t _895 = _894 * _hw_input_s0_x;
     int32_t _896 = _halide_buffer_get_stride(_input_buffer, 2);
     int32_t _897 = _896 * _hw_input_s0_y;
     int32_t _898 = _halide_buffer_get_min(_input_buffer, 1);
     int32_t _899 = _898 * _894;
     int32_t _900 = _halide_buffer_get_min(_input_buffer, 0);
     int32_t _901 = _halide_buffer_get_min(_input_buffer, 2);
     int32_t _902 = _901 * _896;
     int32_t _903 = _900 + _902;
     int32_t _904 = _899 + _903;
     int32_t _905 = _897 - _904;
     int32_t _906 = _895 + _905;
     int32_t _907 = _906 + _hw_input_s0_z;
     uint8_t _908 = ((const uint8_t *)_input)[_907];
     uint16_t _909 = (uint16_t)(_908);
_909;
     uint16_t *_hw_input_stencil_host = (uint16_t *) _hw_input_stencil->host_ptr;
     int32_t _910 = _hw_input_s0_y * 96;
     int32_t _911 = _hw_input_s0_x * 3;
     int32_t _912 = _911 + _hw_input_s0_z;
     int32_t _913 = _910 + _912;
_913;
     _hw_input_stencil_host[_913] = _909;
    } // for _hw_input_s0_z
   } // for _hw_input_s0_x
  } // for _hw_input_s0_y
  // consume hw_input.stencil
  // Allocate shared buffer for _hw_kernel_stencil
  RDAI_MemObject *_hw_kernel_stencil = RDAI_mem_shared_allocate(162);
  // produce hw_kernel.stencil
  for (int _hw_kernel_s0_y = 0; _hw_kernel_s0_y < 0 + 3; _hw_kernel_s0_y++)
  {
   for (int _hw_kernel_s0_x = 0; _hw_kernel_s0_x < 0 + 3; _hw_kernel_s0_x++)
   {
    for (int _hw_kernel_s0_w = 0; _hw_kernel_s0_w < 0 + 3; _hw_kernel_s0_w++)
    {
     for (int _hw_kernel_s0_z = 0; _hw_kernel_s0_z < 0 + 3; _hw_kernel_s0_z++)
     {
      // Provision buffer _hw_kernel_stencil
      int32_t _914 = _halide_buffer_get_stride(_kernel_buffer, 1);
      int32_t _915 = _914 * _hw_kernel_s0_w;
      int32_t _916 = _halide_buffer_get_stride(_kernel_buffer, 2);
      int32_t _917 = _916 * _hw_kernel_s0_x;
      int32_t _918 = _halide_buffer_get_stride(_kernel_buffer, 3);
      int32_t _919 = _918 * _hw_kernel_s0_y;
      int32_t _920 = _halide_buffer_get_min(_kernel_buffer, 1);
      int32_t _921 = _920 * _914;
      int32_t _922 = _halide_buffer_get_min(_kernel_buffer, 0);
      int32_t _923 = _halide_buffer_get_min(_kernel_buffer, 3);
      int32_t _924 = _923 * _918;
      int32_t _925 = _halide_buffer_get_min(_kernel_buffer, 2);
      int32_t _926 = _925 * _916;
      int32_t _927 = _924 + _926;
      int32_t _928 = _922 + _927;
      int32_t _929 = _921 + _928;
      int32_t _930 = _919 - _929;
      int32_t _931 = _917 + _930;
      int32_t _932 = _915 + _931;
      int32_t _933 = _932 + _hw_kernel_s0_z;
      uint8_t _934 = ((const uint8_t *)_kernel)[_933];
      uint16_t _935 = (uint16_t)(_934);
_935;
      uint16_t *_hw_kernel_stencil_host = (uint16_t *) _hw_kernel_stencil->host_ptr;
      int32_t _936 = _hw_kernel_s0_y * 27;
      int32_t _937 = _hw_kernel_s0_x * 9;
      int32_t _938 = _hw_kernel_s0_w * 3;
      int32_t _939 = _938 + _hw_kernel_s0_z;
      int32_t _940 = _937 + _939;
      int32_t _941 = _936 + _940;
_941;
      _hw_kernel_stencil_host[_941] = _935;
     } // for _hw_kernel_s0_z
    } // for _hw_kernel_s0_w
   } // for _hw_kernel_s0_x
  } // for _hw_kernel_s0_y
  // consume hw_kernel.stencil
  // Allocate shared buffer for _hw_output_stencil
  RDAI_MemObject *_hw_output_stencil = RDAI_mem_shared_allocate(4704);
  // produce hw_output.stencil
  // produce _hls_accelerator.hw_output

  RDAI_PlatformType platform_type = RDAI_PlatformType::RDAI_CLOCKWORK_PLATFORM;
  RDAI_Platform **platforms = RDAI_get_platforms_with_type(&platform_type);
  assert(platforms && platforms[0]);
  RDAI_VLNV device_vlnv = {{"aha"}, {"halide_hardware"}, {"resnet_block"}, 1};
  RDAI_Device **devices = RDAI_get_devices_with_vlnv(platforms[0], &device_vlnv);
  assert(devices && devices[0]);
  RDAI_MemObject *mem_obj_list[5] = {
    _hw_input_stencil,
    _hw_kernel_stencil,
    _hw_kernel2_stencil,
    _hw_output_stencil,
    NULL
  };
  RDAI_Status status = RDAI_device_run(devices[0], mem_obj_list);
  RDAI_free_device_list(devices);
  RDAI_free_platform_list(platforms);

  // consume hw_output.stencil
  int32_t _1114 = _halide_buffer_get_min(_output_buffer, 2);
  bool _1115 = 0 <= _1114;
  int32_t _1116 = _halide_buffer_get_extent(_output_buffer, 2);
  int32_t _1117 = _1116 + _1114;
  bool _1118 = _1117 <= 3;
  bool _1119 = _1115 && _1118;
  if (!_1119)   {
   int32_t _1120 = _halide_buffer_get_min(_output_buffer, 2);
   int32_t _1121 = _halide_buffer_get_extent(_output_buffer, 2);
   int32_t _1122 = _1121 + _1120;
   int32_t _1123 = _1122 + -1;
   int32_t _1124 = halide_error_explicit_bounds_too_small(_ucon, "w", "output", 0, 2, _1120, _1123);
   return _1124;
  }
  int32_t _1125 = _halide_buffer_get_min(_output_buffer, 1);
  bool _1126 = 0 <= _1125;
  int32_t _1127 = _halide_buffer_get_extent(_output_buffer, 1);
  int32_t _1128 = _1127 + _1125;
  bool _1129 = _1128 <= 28;
  bool _1130 = _1126 && _1129;
  if (!_1130)   {
   int32_t _1131 = _halide_buffer_get_min(_output_buffer, 1);
   int32_t _1132 = _halide_buffer_get_extent(_output_buffer, 1);
   int32_t _1133 = _1132 + _1131;
   int32_t _1134 = _1133 + -1;
   int32_t _1135 = halide_error_explicit_bounds_too_small(_ucon, "y", "output", 0, 27, _1131, _1134);
   return _1135;
  }
  int32_t _1136 = _halide_buffer_get_min(_output_buffer, 0);
  bool _1137 = 0 <= _1136;
  int32_t _1138 = _halide_buffer_get_extent(_output_buffer, 0);
  int32_t _1139 = _1138 + _1136;
  bool _1140 = _1139 <= 28;
  bool _1141 = _1137 && _1140;
  if (!_1141)   {
   int32_t _1142 = _halide_buffer_get_min(_output_buffer, 0);
   int32_t _1143 = _halide_buffer_get_extent(_output_buffer, 0);
   int32_t _1144 = _1143 + _1142;
   int32_t _1145 = _1144 + -1;
   int32_t _1146 = halide_error_explicit_bounds_too_small(_ucon, "x", "output", 0, 27, _1142, _1145);
   return _1146;
  }
  // produce output
  for (int _output_s0_w = 0; _output_s0_w < 0 + 3; _output_s0_w++)
  {
   for (int _output_s0_y = 0; _output_s0_y < 0 + 28; _output_s0_y++)
   {
    for (int _output_s0_x = 0; _output_s0_x < 0 + 28; _output_s0_x++)
    {
     int32_t _1147 = _output_s0_w * 784;
     int32_t _1148 = _output_s0_y * 28;
     int32_t _1149 = _1148 + _output_s0_x;
     int32_t _1150 = _1147 + _1149;
_1150;
     uint16_t *_hw_output_stencil_host = (uint16_t *) _hw_output_stencil->host_ptr;
     uint16_t _1151 = _hw_output_stencil_host[_1150];
     uint8_t _1152 = (uint8_t)(_1151);
     int32_t _1153 = _halide_buffer_get_stride(_output_buffer, 2);
     int32_t _1154 = _1153 * _output_s0_w;
     int32_t _1155 = _halide_buffer_get_stride(_output_buffer, 1);
     int32_t _1156 = _1155 * _output_s0_y;
     int32_t _1157 = _1154 + _1156;
     int32_t _1158 = _1157 + _output_s0_x;
     ((uint8_t *)_output)[_1158] = _1152;
    } // for _output_s0_x
   } // for _output_s0_y
  } // for _output_s0_w
  // Free shared buffer for hw_output.stencil
  RDAI_mem_free(_hw_output_stencil);
  // Free shared buffer for hw_kernel.stencil
  RDAI_mem_free(_hw_kernel_stencil);
  // Free shared buffer for hw_input.stencil
  RDAI_mem_free(_hw_input_stencil);
  // Free shared buffer for hw_kernel2.stencil
  RDAI_mem_free(_hw_kernel2_stencil);
 } // if _51
 return 0;
}
