# Fix disabled AMD-V in VirtualBox
- This guide shows you how to enable the System -> Processor -> Enable Nested VT-x/AMD-V Feature
- It also configures your system so that Linux OS virtualization works without major problems.
- This example works for an AMD fx-8350 cpu running windows 10.
## Bios
Enter your BIOS and activate the following options:
- Activate IOMMU support
- Activate virtualization
- You can check in windows task manager (Performance Tab) if virtualization is on.
## Windows Hypervisors
- Deactivate all hypervisors from windows features: Hyper-V, Virtual Machine Platform, Windows Hypervisor Platform and Windows Sandbox.
- Open a powershell terminal in admin mode:
1. DISM /Online /Disable-Feature:Microsoft-Hyper-V
2. PowerShell Disable-WindowsOptionalFeature -Online -FeatureName Microsoft-Hyper-V-Hypervisor
3. bcdedit /set hypervisorlaunchtype off
## VirtualBox
- After creating you virtual machine if Enable Nested VT-x/AMD-V Feature is disabled run the following command:
- Open a powershell terminal in admin mode:
VBoxManage modifyvm linuxlabo3_old_1 --nested-hw-virt on