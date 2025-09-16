/**
 * @param {number} init
 * @return {Object}
 */
var createCounter = function(init) {
    let current = init;

    return {
        increment: () => ++current,
        decrement: () => --current,
        reset: () => current = init
    };
};


/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
