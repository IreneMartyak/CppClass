#include <iostream>
#include <memory>
#include <vector>

// Abstract Component
class PacketComponent {
public:
    virtual void display() const = 0;
    virtual ~PacketComponent() = default;
};

// Leaf Component: TCP Header
class TCPHeader : public PacketComponent {
public:
    void display() const override { std::cout << "TCP Header (Source Port, Destination Port, etc.)\n"; }
};

// Leaf Component: Payload
class Payload : public PacketComponent {
public:
    void display() const override { std::cout << "Payload (Data)\n"; }
};

// Leaf Component: Checksum
class Checksum : public PacketComponent {
public:
    void display() const override { std::cout << "Checksum (Integrity Check)\n"; }
};

// Composite Component: TCP Packet
class TCPPacket : public PacketComponent {
private:
    std::vector<std::shared_ptr<PacketComponent>> components_;
    
public:
    void addComponent(std::shared_ptr<PacketComponent> component) {
        components_.push_back(component);
    }
    
    void display() const override {
        std::cout << "TCP Packet Composition:\n";
        for (const auto& component : components_) {
            component->display();
        }
    }
};

int main() {
    // Create individual components
    auto header = std::make_shared<TCPHeader>();
    auto payload = std::make_shared<Payload>();
    auto checksum = std::make_shared<Checksum>();
    
    // Create a composite TCP Packet
    TCPPacket tcpPacket;
    tcpPacket.addComponent(header);
    tcpPacket.addComponent(payload);
    tcpPacket.addComponent(checksum);
    
    // Display the composition of the TCP Packet
    tcpPacket.display();
}