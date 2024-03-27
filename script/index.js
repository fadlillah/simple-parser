const { insertEventIO, toHexString } = require("./client");
// insertEventIO(71, 1);
// insertEventIO(72, 1);
insertEventIO(11, 0x0994, 2);
insertEventIO(12, 0xff2c, 2);
//const data = toHexString();
const data = "0000000000001a7e010000000000017f360000000100000001004712120000000000000100008612";
console.log(`This is hex data to send: ${data}`);

const { parseHexString } = require("./server");
console.log(JSON.stringify(parseHexString(data), null, 2));