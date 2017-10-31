package main

import (
	"net/http"
	"fmt"
	"io/ioutil"
	"errors"
)

func main() {
	fmt.Println("Sending web request to x.com...")
	req, err := Get("http://x.com")
	if err != err {
		fmt.Println("there was an error")
	}
	fmt.Println("The response from x.com was: '" + req + "'")
}

func Get(url string) (string, error) {
	resp, err := http.Get(url)
	if err != nil {
		return "", errors.New(err.Error())
	}
	defer resp.Body.Close()
	bs, err2 := ioutil.ReadAll(resp.Body)
	if err2 != nil {
		return "", errors.New(err2.Error())
	}
	return string(bs), nil
}
