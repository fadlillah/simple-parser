const { insertEventIO, toHexString } = require("./client");
insertEventIO(71, 1);
insertEventIO(72, 1);
insertEventIO(73, 2, 2);
insertEventIO(74, 2, 2);
// const data = toHexString();
const data = "00000000000000167e010000000000000be800000000000000000000000000000100008612";
console.log(`This is hex data to send: ${data}`);

const { parseHexString } = require("./server");
console.log(JSON.stringify(parseHexString(data), null, 2));