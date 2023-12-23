# VoIPCore

## VoIPCore
VoIPCore is an Voice Over IP (VOIP) protocol, voice communication over the internet. This project encompasses a bespoke binary protocol, a client-server architecture where voice transport occurs directly between clients, and a comprehensive set of tools for both users and server administrators.

## Features
- **Binary VOIP Protocol**: A custom-built, efficient binary protocol for seamless voice communication.
- **Client-Server Architecture**: Allows for direct client-to-client voice transport, with server proxy support for conference calls and NAT-ed clients.
- **PortAudio Integration**: Utilizes PortAudio (19.7.0) for high-fidelity sound handling.
- **Opus Compression**: Incorporates Opus (1.3.1) codec for optimal sound compression and clarity.
- **Qt GUI Client**: A user-friendly client interface built with Qt (5.15.2), ensuring a smooth user experience.
- **Server-Side Networking**: Powered by ASIO (1.19.2) for robust and efficient server-side networking.
- **Storage Solutions**: Employs sqlite3 and/or sqlite_orm for secure and efficient data storage.

## Components
- **Protocol Documentation**: Detailed documentation of the custom binary protocol.
- **UML Compliant Class Diagram**: Fully compliant class diagrams for both client and server architectures.
- **Network Abstraction Layers**: Custom implementations for server-side (ASIO) and client-side (Qt Network) networking.
- **C++ Abstractions**: Abstract layers for PortAudio and Opus, facilitating the integration of these C libraries.
- **Contact List and Call Features**: Features include a contact list, making and hanging up calls.


## Acknowledgments
This project was undertaken as part of my academic studies, in close collaboration with my colleagues Tristan, Tom, and Manuel. 
