const { insertEventIO, toHexString } = require("./client");
insertEventIO(71, 1);
insertEventIO(72, 1);
insertEventIO(73, 2, 2);
insertEventIO(74, 2, 2);
// const data = toHexString();
const data = "00000000000000247e01000000000000080e000000040002004701004801000200490002004a00020000000000000100008612";
console.log(`This is hex data to send: ${data}`);

const { parseHexString } = require("./server");
console.log(JSON.stringify(parseHexString(data), null, 2));