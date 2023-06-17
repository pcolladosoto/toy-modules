Vagrant.configure("2") do |config|
    config.vm.box = "almalinux/9"
    config.ssh.forward_agent = true
    config.ssh.forward_x11 = true

    config.vm.provider "virtualbox" do |v|
        v.customize ["modifyvm", :id, "--memory", 1024]
    end

    config.vm.define "kmodvm" do |devvm|
        devvm.vm.hostname = 'kmodvm'
        devvm.vm.network :private_network, ip: "10.0.123.2"
    end
end
