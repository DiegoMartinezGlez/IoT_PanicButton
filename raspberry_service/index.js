const http = require('http')
const moment = require('moment')

console.log('Starting service ...')

http.createServer((request, response) => {

  // TODO: get params from query string

  // const timeStamp = Math.floor(Date.now() / 1000)
  const now = moment().format('HH:mm:ss (DD/MM/YYYY)')

  console.log(`Received request at ${now}.`)

  // YOU CAN DO YOUR CUSTOM ACTION HERE: 
  // store something in database, trigger something ...

  response.write( 'Request received: ' + now )
  response.end()

}).listen(3030) // YOU CAN CHANGE PORT HERE, default=3030
