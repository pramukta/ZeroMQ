:Evaluate:			BeginPackage["ZeroMQ`"]
:Evaluate:			Begin["`Private`"]

:Begin:
:Function:			zmq_send_c
:Pattern:			ZMQSend[socket_integer, message_String, option_Integer]
:Arguments:			{socket, message, option}
:ArgumentTypes:		        {Integer, String, Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_recv_c
:Pattern:			ZMQRecv[socket_integer, option_Integer]
:Arguments:			{socket, option}
:ArgumentTypes:		        {Integer, Integer}
:ReturnType:		        Manual
:End:

:Begin:
:Function:			zmq_bind_c
:Pattern:			ZMQBind[socket_Integer, endpoint_String]
:Arguments:			{socket, endpoint}
:ArgumentTypes:		        {Integer, String}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_close_c
:Pattern:			ZMQClose[socket_Integer]
:Arguments:			{socket}
:ArgumentTypes:		        {Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_connect_c
:Pattern:			ZMQConnect[socket_Integer, endpoint_String]
:Arguments:			{socket, endpoint}
:ArgumentTypes:		        {Integer, String}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_device_c
:Pattern:			ZMQDevice[device_Integer, fsocket_Integer, bsocket_Integer]
:Arguments:			{device, fsocket, bsocket}
:ArgumentTypes:		        {Integer, Integer, Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_init_c
:Pattern:			ZMQInit[nthreads_Integer]
:Arguments:			{nthreads}
:ArgumentTypes:		        {Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_socket_c
:Pattern:			ZMQSocket[context_Integer, type_Integer]
:Arguments:			{context, type}
:ArgumentTypes:		        {Integer, Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_term_c
:Pattern:			ZMQTerminate[context_Integer]
:Arguments:			{context}
:ArgumentTypes:		        {Integer}
:ReturnType:		        Integer
:End:

:Begin:
:Function:			zmq_version_c
:Pattern:			ZMQVersion[]
:Arguments:			{}
:ArgumentTypes: 	        {}
:ReturnType:		        Manual
:End:


:Evaluate:			End[]
:Evaluate:			EndPackage[]