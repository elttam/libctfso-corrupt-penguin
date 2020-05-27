# Overview

libctfso-corrupt-penguin is a bundle of Linux CTF challenges requiring
memory corruption to solve.

Works out of the box on my machine, YMMV - PR's welcome.

# Prerequisites

To use this bundle you should have [Vagrant](https://www.vagrantup.com)
installed along with one of the following hypervisors:

* Virtualbox
* Hyper-V
* Parallels
* libvirt+QEMU
* VMWare Desktop (should work but not tested)

If you know what you're doing and prefer to manage deployment yourself, you can
simply run the [Ansible](https://www.ansible.com/)
[playbook](./ansible/site.yml) on a [Ubuntu Xenial
amd64](http://releases.ubuntu.com/xenial/) target.

## Notes

If you are using Parallels or libvirt+QEMU, please ensure you have `rsync`
installed locally.

If this is your first time using Vagrant with libvirt, please run `vagrant
plugin install vagrant-libvirt`.

If this is your first time using Vagrant with Parallels, please run `vagrant
plugin install vagrant-parallels`.

If this is your first time using Vagrant with Hyper-V, please run all commands
from an Administrator console. In addition, you will be asked to enter your
Windows username/password to enable shared folder support for provisioning.

# Usage

The following command will download a Ubuntu 16.04 VM template from VagrantHub,
create a new virtual machine for 'libctfso-corrupt-penguin', and build/install
challenges under the `/challenges` directory of the VM:

**Note:** This can take a while the first time you run it depending on your host
specs and internet connection.

```sh
vagrant up
```

You can re-provision anytime with:

```sh
vagrant provision
```

You can connect to the virtual machine with:

```sh
vagrant ssh
```

This will login to the virtual machine using the 'vagrant' user account,
which has `sudo` privileges so that you can install any additional packages that
you want.

You can stop the virtual machine with:

```sh
vagrant halt
```

And delete the virtual machine with:

```sh
vagrant destroy
```

# Challenges

You should switch to the 'hahn' user account (password = 'hahn') when you are
ready to play:

```sh
su - hahn
```

All challenges can be found under the `/challenges/` directory.

Difficulty estimates are relative to other challenges in this bundle.

---

**Title:** shock  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{92f414e5-a356-4756-a356-ace57d8c8fbf}`  
**Relative Difficulty:** Trivial  

---

**Title:** sd  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{e74f0007-b822-4885-b24d-124e0f173cde}`  
**Relative Difficulty:** Easy  

---

**Title:** bblinus  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{b3876765-d30f-46c2-afab-21c43d789a40}`  
**Relative Difficulty:** Medium  

---

**Title:** thenewsh  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{bffb4bae-5c2c-4752-8b61-171a1fb78a49}`  
**Relative Difficulty:** Trivial  

---

**Title:** switcheroo  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{8329a8c6-b271-400b-991f-26138cfc45e7}`  
**Relative Difficulty:** Hard  

---

**Title:** neoboffy  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{fb8e2b47-7724-41b2-9362-10faff1e84bf}`  
**Relative Difficulty:** Medium  

---

**Title:** beatbox  
**Category:** Linux Memory Corruption  
**Flag:** `libctf{30d95a92-0ef6-47c3-9dd7-cbb45daa9431}`  
**Relative Difficulty:** Medium  

---

# Hints

Each challenge directory should have everything you need to figure out a plan of
attack. If you really want, you can treat this source repository as an oracle by
asking it questions like:

```
hahn@apocalypse:~/libctfso-corrupt-penguin/ansible/roles$ grep -iR 'randomize_va_space' . >/dev/null && true || false
hahn@apocalypse:~/libctfso-corrupt-penguin/ansible/roles$ echo $?
0
hahn@apocalypse:~/libctfso-corrupt-penguin/ansible/roles$ grep -iR 'idontexist' . >/dev/null && true || false
hahn@apocalypse:~/libctfso-corrupt-penguin/ansible/roles$ echo $?
1
hahn@apocalypse:~/libctfso-corrupt-penguin/ansible/roles$ 
```
