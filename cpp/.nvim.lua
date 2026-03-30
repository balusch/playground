local function task(name)
  vim.cmd("AsyncTask " .. name)
end

vim.api.nvim_create_autocmd("FileType", {
  pattern = { "c", "cpp", "cc", "h", "hpp" },
  callback = function()
    vim.opt_local.shiftwidth = 2
    vim.opt_local.tabstop = 2
    vim.opt_local.softtabstop = 2
    vim.opt_local.expandtab = true
  end,
})

vim.api.nvim_create_user_command("CppConfigure", function()
  task("configure-debug")
end, { desc = "Configure the debug preset" })

vim.api.nvim_create_user_command("CppBuild", function()
  task("c-build-debug")
end, { desc = "Build the debug preset" })

vim.api.nvim_create_user_command("CppRun", function()
  task("c-run-debug")
end, { desc = "Run the current debug target" })

vim.api.nvim_create_user_command("CppTest", function()
  task("c-test")
end, { desc = "Run tests for the current target or preset" })

vim.api.nvim_create_autocmd("FileType", {
  pattern = { "c", "cpp", "cc" },
  callback = function(args)
    local opts = { buffer = args.buf, silent = true }

    vim.keymap.set("n", "<Leader>rc", function()
      task("configure-debug")
    end, vim.tbl_extend("force", opts, { desc = "C++: configure debug preset" }))

    vim.keymap.set("n", "<Leader>rb", function()
      task("build-current")
    end, vim.tbl_extend("force", opts, { desc = "C++: build current target" }))

    vim.keymap.set("n", "<Leader>rr", function()
      task("run-current")
    end, vim.tbl_extend("force", opts, { desc = "C++: run current target" }))

    vim.keymap.set("n", "<Leader>rt", function()
      task("test-current")
    end, vim.tbl_extend("force", opts, { desc = "C++: test current target" }))
  end,
})
