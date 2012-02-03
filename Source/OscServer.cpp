
#include "OscServer.h"
#include "OscAction.h"
#include "../Libraries/osc/OscOutboundPacketStream.h"
#include "../Libraries/osc/OscOutboundPacketStream.h"

void OscServer::send(OscAction* action){
  char buffer[bufsize];
  osc::OutboundPacketStream stream(buffer, bufsize);
  stream << osc::BeginBundleImmediate
	 << osc::BeginMessage(action->prefix.toUTF8())
	 << action->value << action->suffix.toUTF8()
	 << osc::EndMessage << osc::EndBundle;

  DatagramSocket socket(0);
  socket.connect(hostname, port);
//   socket.waitUntilReady(false, 10);
  socket.write(stream.Data(), stream.Size());
  socket.close();
}

