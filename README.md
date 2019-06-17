# Covert Channel
This project has been implemented as part of Cryptography signature in the Factultad de Ingeniería de la Universidad de Buenos Aires.

## Compilation
In order to compile the project, it is provided a CMake. User must run the following commands from the root folder:

```sh
mkdir build
cd build
cmake ..
make
```

## Execution
Once the project is compiled, there are two modes to run the program: as a sender, and as a receiver. Both of those modes need to run with root permissions, since it works with raw sockets.
- To run the program as a sender, user must pass a dummy file name to send in the body of the udp messages. The actual message will be sent as part of the UDP header.
- To run the program as a receiver, user must not pass any parameter to the executable.

Since the build folder:
```sh
# As sender
sudo ./bin/covertudp ../test/lorem_ipsum.txt

# As receiver
sudo ./bin/covertudp
```

The standard input of the sender should be written in the standard output of the receiver.
