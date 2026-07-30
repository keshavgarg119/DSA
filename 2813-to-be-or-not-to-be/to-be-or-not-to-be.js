/**
 * @param {string} val
 * @return {Object}
 */
function expect(x) {

    function toBe(val) {
        if(x === val) return true;

        throw new Error("Not Equal");
    }

    function notToBe(val) {
        if(x !== val) return true;
        
        throw new Error("Equal");
    }

    return {toBe, notToBe};
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */