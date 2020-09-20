1. Connect to the Atlas200dk using ssh `ssh HwHiAiUser@192.168.1.49` with password `Mind@123`
2. Switch to root using `su root` and the same password
3. Go to atlas200dk/script/ and launch `./run_presenter_server.sh`
4. With the web browser, connect to the Atlas200dk on port 7007
5. Go to atlas200dk/out/ and launch `./main --send_mode uart --channel Channel-0`
